pub mod heap;
pub mod max_heap;
pub mod min_heap;

use std::{error::Error, fmt::Display};

#[derive(Debug)]
pub struct HeapOverflowError;
impl Error for HeapOverflowError {}
impl Display for HeapOverflowError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Heap overflow error occurred.")
    }
}

#[derive(Debug)]
pub struct HeapUnderflowError;
impl Error for HeapUnderflowError {}
impl Display for HeapUnderflowError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Heap underflow error occurred.")
    }
}

#[derive(Debug)]
pub struct HeapInvalidIndexError;
impl Error for HeapInvalidIndexError {}
impl Display for HeapInvalidIndexError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Heap invalid index error occurred.")
    }
}

pub enum HeapError {
    HeapOverflowError,
    HeapUnderflowError,
    HeapInvalidIndexError,
}
