/// Queue
use std::io::{Error, ErrorKind};

#[derive(PartialEq)]
pub struct Queue<T> {
    data: Vec<T>,
    capacity: usize,
    size: usize,
    front: usize,
    rear: usize,
}

impl<T> Queue<T> {
    pub fn new(capacity: usize) -> Self {
        let mut data = Vec::with_capacity(capacity);
        unsafe {
            data.set_len(capacity);
        }

        Queue {
            data,
            capacity,
            size: 0,
            front: 0,
            rear: capacity - 1,
        }
    }

    pub fn size(&self) -> usize {
        self.size
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }

    pub fn is_full(&self) -> bool {
        self.size == self.capacity
    }

    pub fn front(&self) -> Option<&T> {
        if self.is_empty() {
            return None;
        }

        Some(&self.data[self.front])
    }

    pub fn enqueue(&mut self, data: T) -> Result<(), Error> {
        if self.is_full() {
            return Err(Error::new(
                ErrorKind::Other,
                "Stack overflow, could not push",
            ));
        }

        self.rear = (self.rear + 1) % self.capacity;
        self.data[self.rear] = data;
        self.size += 1;
        Ok(())
    }

    pub fn dequeue(&mut self) -> Result<&T, Error> {
        if self.is_empty() {
            return Err(Error::new(
                ErrorKind::Other,
                "Stack underflow, could not pop",
            ));
        }

        let removed = &self.data[self.front];
        self.front = (self.front + 1) % self.capacity;
        self.size -= 1;
        Ok(removed)
    }
}
