use std::fmt::Display;

use super::{heap::Heap, HeapError};

pub struct MinHeap<T>
where
    T: PartialOrd + Default + Copy + Display,
{
    data: Vec<T>,
    sz: usize,
    cap: usize,
}

const DEFAULT_CAP: usize = 10;

impl<T> MinHeap<T>
where
    T: PartialOrd + Default + Copy + Display,
{
    pub fn new(cap: Option<usize>) -> Self {
        MinHeap {
            data: vec![Default::default(); cap.unwrap_or(DEFAULT_CAP)],
            sz: 0,
            cap: cap.unwrap_or(DEFAULT_CAP),
        }
    }

    pub fn size(&self) -> usize {
        self.sz
    }

    pub fn set_size(&mut self, size: usize) {
        self.sz = size;
    }

    pub fn data(&self) -> &Vec<T> {
        &self.data
    }
}

impl<T> Heap<T> for MinHeap<T>
where
    T: PartialOrd + Default + Copy + Display,
{
    fn heapify(&mut self, index: usize) {
        let left = MinHeap::<T>::left(index);
        let right = MinHeap::<T>::right(index);
        let mut smallest = if left < self.sz && self.data[left] < self.data[index] {
            left
        } else {
            index
        };

        if right < self.sz && self.data[right] < self.data[smallest] {
            smallest = right;
        }

        if smallest != index {
            self.data.swap(index, smallest);
            self.heapify(smallest);
        }
    }

    fn insert(&mut self, value: T) -> Result<(), HeapError> {
        if self.is_full() {
            return Err(HeapError::HeapOverflowError);
        }

        self.data[self.sz] = value;
        let mut cur = self.sz;
        while cur > 0 && self.data[cur] < self.data[MinHeap::<T>::parent(cur)] {
            self.data.swap(cur, MinHeap::<T>::parent(cur));
            cur = MinHeap::<T>::parent(cur);
        }

        self.sz += 1;
        Ok(())
    }

    fn remove(&mut self, index: usize) -> Result<T, HeapError> {
        if self.is_empty() {
            return Err(HeapError::HeapUnderflowError);
        }

        if index >= self.sz {
            return Err(HeapError::HeapInvalidIndexError);
        }

        let removed = self.data[index];
        self.sz -= 1;
        self.data[index] = self.data[self.sz];
        self.heapify(index);

        Ok(removed)
    }

    fn is_empty(&self) -> bool {
        self.sz == 0
    }

    fn is_full(&self) -> bool {
        self.sz == self.cap
    }
}

impl<T> Default for MinHeap<T>
where
    T: PartialOrd + Default + Copy + Display,
{
    fn default() -> Self {
        Self::new(None)
    }
}

impl<T> Display for MinHeap<T>
where
    T: PartialOrd + Default + Copy + Display,
{
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut out = String::new();
        let mut break_line = 0;

        for i in 0..self.sz / 2 {
            if i == 0 {
                out.push_str(format!("({} [{}])\n", self.data[i], i).as_str());
            }

            out.push_str(
                format!(
                    "({} [{}]) ({} [{}])",
                    self.data[MinHeap::<T>::left(i)],
                    MinHeap::<T>::left(i),
                    self.data[MinHeap::<T>::right(i)],
                    MinHeap::<T>::right(i)
                )
                .as_str(),
            );

            if i == break_line {
                out.push_str("\n");
                break_line = 2 * break_line + 2;
            } else {
                out.push_str(" | ");
            }
        }

        write!(f, "{}", out)
    }
}
