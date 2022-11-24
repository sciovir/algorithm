/// Linked List is a linear data structure. Unlike arrays, linked list elements
/// are not stored at a contiguous location the elements are linked using
/// pointers. Singly linked list is represented by a pointer to the first node
/// called head, if linked list is empty then the value of head is NULL (None).
/// Each node of a singly linked list contains 2 parts:
///   - Stored data
///   - Pointer to the next node (or reference)
///      HEAD
///    [data1|-]->[data2|-]->[data3|-]->[data4|-]->[data5|-]->NULL
pub struct Node<T: PartialOrd> {
    data: T,
    next: Option<Box<Node<T>>>,
}

impl<T> Node<T>
where
    T: PartialOrd,
{
    fn new(data: T, next: Option<Box<Node<T>>>) -> Node<T> {
        Node { data, next }
    }
}

pub struct SinglyLinkedList<T: PartialOrd> {
    head: Option<Box<Node<T>>>,
    size: usize,
}

impl<T> SinglyLinkedList<T>
where
    T: PartialOrd,
{
    pub fn new(head: Option<Box<Node<T>>>, sz: Option<usize>) -> Self {
        SinglyLinkedList {
            head,
            size: sz.unwrap_or(0),
        }
    }

    pub fn is_empty(&self) -> bool {
        self.head.is_none()
    }

    pub fn search(&self, data: T) -> bool {
        let mut tmp = self.head.as_ref();
        while let Some(node) = tmp {
            if node.data == data {
                return true;
            }
            tmp = node.next.as_ref();
        }

        false
    }

    pub fn insert(&mut self, data: T) {
        let node = Node::new(data, None);

        if self.is_empty() {
            self.head = Some(Box::new(node));
        } else {
            let mut tmp = self.head.as_mut();
            while let Some(tmp_node) = tmp {
                if tmp_node.next.is_some() {
                    tmp = tmp_node.next.as_mut();
                } else {
                    break;
                }
            }

            if let Some(tmp_node) = tmp {
                tmp_node.next = Some(Box::new(node));
            }
        }

        self.size += 1;
    }
}
