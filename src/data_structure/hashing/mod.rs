pub mod open_addressing;
pub mod separate_chaining;

use std::{error::Error, fmt::Display};

#[derive(Debug)]
pub struct HashTableOverflowError;
impl Error for HashTableOverflowError {}
impl Display for HashTableOverflowError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Hash table overflow error occurred.")
    }
}

#[derive(Debug)]
pub struct HashTableKeyNotExistError;
impl Error for HashTableKeyNotExistError {}
impl Display for HashTableKeyNotExistError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Hash table key not exist error occurred.")
    }
}

#[derive(Debug)]
pub struct HashTableKeyAlreadyExistError;
impl Error for HashTableKeyAlreadyExistError {}
impl Display for HashTableKeyAlreadyExistError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Hash table key already exist error occurred.")
    }
}

pub enum HashTableError {
    HashTableOverflowError,
    HashTableKeyNotExistError,
    HashTableKeyAlreadyExistError,
}
