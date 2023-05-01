use std::fmt::Display;

use super::HashTableError;

pub struct HashTable<K, V>
where
    K: PartialOrd + Default + Copy + Display + TryFrom<K> + TryInto<isize>,
    V: PartialOrd + Default + Copy + Display,
{
    keys: Vec<Option<K>>,
    values: Vec<Option<V>>,
    sz: usize,
    cap: usize,
}

const DEFAULT_CAP: usize = 10;

impl<K, V> HashTable<K, V>
where
    K: PartialOrd + Default + Copy + Display + TryFrom<K> + TryInto<isize>,
    V: PartialOrd + Default + Copy + Display,
{
    pub fn new(cap: Option<usize>) -> Self {
        HashTable {
            keys: vec![None; cap.unwrap_or(DEFAULT_CAP)],
            values: vec![None; cap.unwrap_or(DEFAULT_CAP)],
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

    pub fn keys(&self) -> &Vec<Option<K>> {
        &self.keys
    }

    fn hashing(&self, key: K) -> Result<usize, HashTableError> {
        let result: Result<isize, _> = key.try_into();
        match result {
            Ok(val) => {
                let mut hash: isize = val % self.cap as isize;
                if hash < 0 {
                    hash += self.cap as isize;
                }

                return Ok(hash as usize);
            }
            Err(_) => {
                return Err(HashTableError::HashTableKeyHashingError);
            }
        }
    }

    fn rehashing(&self) -> Result<usize, HashTableError> {
        for i in 0..self.cap {
            if self.keys[i].is_none() {
                return Ok(i);
            }
        }

        Err(HashTableError::HashTableOverflowError)
    }

    pub fn get(&self, key: K) -> Result<V, HashTableError> {
        let mut index = 0;
        for i in 0..self.cap {
            if self.keys[i].is_some() && self.keys[i].unwrap() == key {
                index = i;
                break;
            }
        }

        if index > self.cap - 1 {
            return Err(HashTableError::HashTableKeyNotExistError);
        }

        Ok(self.values[index].unwrap())
    }

    pub fn insert(&mut self, key: K, value: V) -> Result<(), HashTableError> {
        for i in 0..self.cap {
            if self.keys[i].is_some() && self.keys[i].unwrap() == key {
                return Err(HashTableError::HashTableKeyAlreadyExistError);
            }
        }

        let mut hash = self.hashing(key)?;
        if self.keys[hash].is_some() {
            hash = self.rehashing()?;
        }

        self.keys[hash] = Some(key);
        self.values[hash] = Some(value);

        self.sz += 1;
        Ok(())
    }

    pub fn remove(&mut self, key: K) -> Result<V, HashTableError> {
        let mut index = 0;
        for i in 0..self.cap {
            if self.keys[i].is_some() && self.keys[i].unwrap() == key {
                index = i;
                break;
            }
        }

        if index > self.cap - 1 {
            return Err(HashTableError::HashTableKeyNotExistError);
        }

        let removed = self.values[index].unwrap();
        self.keys[index] = None;
        self.values[index] = None;

        self.sz -= 1;
        Ok(removed)
    }
}

impl<K, V> HashTable<K, V>
where
    K: PartialOrd + Default + Copy + Display + TryFrom<K> + TryInto<isize>,
    V: PartialOrd + Default + Copy + Display,
{
    fn default() -> Self {
        Self::new(None)
    }
}

impl<K, V> HashTable<K, V>
where
    K: PartialOrd + Default + Copy + Display + TryFrom<K> + TryInto<isize>,
    V: PartialOrd + Default + Copy + Display,
{
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut out = String::new();

        if self.is_empty() {
            out.push_str("Empty hash table");
        } else {
            for i in 0..self.cap {
                if self.keys[i].is_some() {
                    out.push_str(
                        format!("({}: {}) ", self.keys[i].unwrap(), self.values[i].unwrap())
                            .as_str(),
                    )
                }
            }
        }

        write!(f, "{}", out)
    }
}
