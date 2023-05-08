use std::{
    collections::hash_map::DefaultHasher,
    fmt::Display,
    hash::{Hash, Hasher},
};

use super::HashTableError;

pub struct HashTable<K, V>
where
    K: PartialOrd + Default + Display + Clone + Hash,
    V: PartialOrd + Default + Display,
{
    table: Vec<Option<(K, V)>>,
    sz: usize,
    cap: usize,
}

const DEFAULT_CAP: usize = 10;

impl<K, V> HashTable<K, V>
where
    K: PartialOrd + Default + Display + Clone + Hash,
    V: PartialOrd + Default + Display + Clone,
{
    pub fn new(cap: Option<usize>) -> Self {
        HashTable {
            table: vec![None; cap.unwrap_or(DEFAULT_CAP)],
            sz: 0,
            cap: cap.unwrap_or(DEFAULT_CAP),
        }
    }

    pub fn size(&self) -> usize {
        self.sz
    }

    pub fn is_empty(&self) -> bool {
        self.sz == 0
    }

    pub fn keys(&self) -> Vec<K> {
        let mut ret = Vec::new();

        for i in 0..self.cap {
            if let Some((key, _)) = self.table[i].as_ref() {
                ret.push(key.clone())
            }
        }

        ret
    }

    pub fn get(&self, key: &K) -> Result<&V, HashTableError> {
        let hash = self.hashing(key);
        match self.table[hash].as_ref() {
            Some(tup) => {
                if tup.0 == *key {
                    return Ok(&tup.1);
                }
            }
            None => {}
        }

        let index = self.find_key_index(key)?;
        match self.table[index].as_ref() {
            Some((_, value)) => Ok(value),
            None => Err(HashTableError::HashTableKeyNotExistError),
        }
    }

    pub fn insert(&mut self, key: K, value: V) -> Result<(), HashTableError> {
        let mut hash = self.hashing(&key);
        if let Some(tup) = self.table[hash].as_ref() {
            if tup.0 == key {
                return Err(HashTableError::HashTableKeyAlreadyExistError);
            }
        }

        for i in 0..self.cap {
            if let Some(tup) = self.table[i].as_ref() {
                if tup.0 == key {
                    return Err(HashTableError::HashTableKeyAlreadyExistError);
                }
            }
        }

        if self.table[hash].is_some() {
            hash = self.rehashing(hash)?;
        }

        self.table[hash] = Some((key, value));
        self.sz += 1;

        Ok(())
    }

    pub fn remove(&mut self, key: K) -> Result<(K, V), HashTableError> {
        let index = self.find_key_index(&key)?;

        let removed = self.table[index].clone().unwrap();
        self.table[index] = None;
        self.sz -= 1;

        Ok(removed)
    }

    fn hashing(&self, key: &K) -> usize {
        let mut hasher = DefaultHasher::new();
        key.hash(&mut hasher);
        let ret = hasher.finish() as usize;
        ret % self.cap
    }

    fn rehashing(&self, value: usize) -> Result<usize, HashTableError> {
        for i in 0..self.cap {
            let index = (value + i) % self.cap;
            if self.table[index].is_none() {
                return Ok(index);
            }
        }

        Err(HashTableError::HashTableOverflowError)
    }

    fn find_key_index(&self, key: &K) -> Result<usize, HashTableError> {
        let mut index = self.cap;
        for i in 0..self.cap {
            if let Some(tup) = self.table[i].as_ref() {
                if tup.0 == *key {
                    index = i;
                    break;
                }
            }
        }

        if index == self.cap {
            return Err(HashTableError::HashTableKeyNotExistError);
        }

        Ok(index)
    }
}

impl<K, V> Default for HashTable<K, V>
where
    K: PartialOrd + Default + Display + Clone + Hash,
    V: PartialOrd + Default + Display + Clone,
{
    fn default() -> Self {
        Self::new(None)
    }
}

impl<K, V> Display for HashTable<K, V>
where
    K: PartialOrd + Default + Display + Clone + Hash,
    V: PartialOrd + Default + Display + Clone,
{
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut out = String::new();

        if self.is_empty() {
            out.push_str("Empty hash table");
        } else {
            for i in 0..self.cap {
                if let Some((key, value)) = self.table[i].as_ref() {
                    out.push_str(format!("({}: {}) ", key, value).as_str())
                }
            }
        }

        write!(f, "{}", out)
    }
}
