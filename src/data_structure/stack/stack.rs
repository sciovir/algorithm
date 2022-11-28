/// Stack
use std::io::{Error, ErrorKind};

#[derive(PartialEq)]
pub struct Stack<T> {
    data: Vec<T>,
    capacity: usize,
    top: isize,
}

impl<T> Stack<T> {
    pub fn new(capacity: usize) -> Self {
        Stack {
            data: Vec::with_capacity(capacity),
            capacity,
            top: -1,
        }
    }

    pub fn size(&self) -> usize {
        (self.top + 1) as usize
    }

    pub fn is_empty(&self) -> bool {
        self.top < 0
    }

    pub fn is_full(&self) -> bool {
        self.size() == self.capacity
    }

    pub fn top(&self) -> Option<&T> {
        if self.is_empty() {
            return None;
        }

        Some(&self.data[self.top as usize])
    }

    pub fn push(&mut self, data: T) -> Result<(), Error> {
        if self.is_full() {
            return Err(Error::new(
                ErrorKind::Other,
                "Stack overflow, could not push",
            ));
        }

        self.top += 1;
        self.data[self.top as usize] = data;
        Ok(())
    }

    pub fn pop(&mut self) -> Result<&T, Error> {
        if self.is_empty() {
            return Err(Error::new(
                ErrorKind::Other,
                "Stack underflow, could not pop",
            ));
        }

        let removed = &self.data[self.top as usize];
        self.top -= 1;
        Ok(removed)
    }
}
