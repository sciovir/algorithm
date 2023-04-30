use std::fmt::Display;

use super::HeapError;

pub trait Heap<T: PartialOrd + Default + Copy + Display> {
    fn heapify(&mut self, index: usize);
    fn insert(&mut self, value: T) -> Result<(), HeapError>;
    fn remove(&mut self, index: usize) -> Result<T, HeapError>;
    fn is_empty(&self) -> bool;
    fn is_full(&self) -> bool;

    fn parent(index: usize) -> usize {
        (index - 1) / 2
    }

    fn left(index: usize) -> usize {
        2 * index + 1
    }

    fn right(index: usize) -> usize {
        2 * index + 2
    }
}
