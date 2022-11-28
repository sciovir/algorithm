/// Linked List is a linear data structure. Unlike arrays, linked list elements
/// are not stored at a contiguous location the elements are linked using
/// pointers. Singly linked list is represented by a pointer to the first node
/// called head, if linked list is empty then the value of head is NULL (None).
/// Each node of a singly linked list contains 2 parts:
/// - Stored data
/// - Pointer to the next node (or reference)
///   HEAD
/// [data1|-]->[data2|-]->[data3|-]->[data4|-]->[data5|-]->NULL
use std::io::{Error, ErrorKind};
use std::ptr;

struct Node<T: PartialOrd> {
    data: T,
    next: *mut Node<T>,
}

impl<T> Node<T>
where
    T: PartialOrd,
{
    fn new(data: T) -> Self {
        Node {
            data,
            next: ptr::null_mut(),
        }
    }
}

pub struct SLinkedList<T: PartialOrd> {
    head: *mut Node<T>,
    size: usize,
}

impl<T> SLinkedList<T>
where
    T: PartialOrd,
{
    pub fn new() -> Self {
        SLinkedList {
            head: ptr::null_mut(),
            size: 0,
        }
    }

    pub fn size(&self) -> usize {
        self.size
    }

    pub fn is_empty(&self) -> bool {
        self.head.is_null()
    }

    pub fn insert(&mut self, data: T) {
        let node = Box::into_raw(Box::new(Node::new(data)));
        if self.is_empty() {
            self.head = node;
        } else {
            let mut tmp = self.head;
            unsafe {
                while !(*tmp).next.is_null() {
                    tmp = (*tmp).next;
                }
                (*tmp).next = node;
            }
        }
        self.size += 1;
    }

    pub fn remove(&mut self, data: T) -> Result<(), Error> {
        if self.is_empty() {
            return Err(Error::new(
                ErrorKind::Other,
                "List is empty, could not remove",
            ));
        }

        let mut old = self.head;
        let mut prev = ptr::null_mut();

        unsafe {
            while !old.is_null() && (*old).data != data {
                prev = old;
                old = (*old).next;
            }

            if old.is_null() {
                return Err(Error::new(
                    ErrorKind::InvalidInput,
                    "Node is not exist in this list",
                ));
            }

            if old == self.head {
                self.head = (*self.head).next;
            } else {
                (*prev).next = (*old).next;
            }

            ptr::drop_in_place(old);
        }

        self.size -= 1;
        Ok(())
    }

    pub fn search(&self, data: T) -> bool {
        let mut tmp = self.head;
        unsafe {
            while !tmp.is_null() {
                if (*tmp).data == data {
                    return true;
                }

                tmp = (*tmp).next;
            }
        }
        false
    }
}

impl<T> Drop for SLinkedList<T>
where
    T: PartialOrd,
{
    fn drop(&mut self) {
        let mut tmp = self.head;
        unsafe {
            while !tmp.is_null() {
                ptr::drop_in_place(tmp);
                tmp = (*tmp).next;
            }
        }
    }
}
