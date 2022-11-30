use algorithm::data_structure::queue::*;

// Queue
#[test]
fn queue_methods_should_handle_data_correctly() {
    let mut queue = queue::Queue::new(8);

    assert!(queue.is_empty());
    assert!(!queue.is_full());
    assert_eq!(queue.size(), 0);

    assert!(queue.enqueue(8).is_ok());
    assert!(queue.enqueue(6).is_ok());
    assert!(queue.enqueue(26).is_ok());
    assert!(queue.enqueue(29).is_ok());
    assert!(queue.enqueue(2).is_ok());
    assert!(queue.enqueue(9).is_ok());
    assert!(queue.enqueue(7).is_ok());
    assert!(queue.enqueue(22).is_ok());

    assert!(!queue.is_empty());
    assert_eq!(queue.size(), 8);
    assert!(queue.is_full());

    assert!(queue.enqueue(19).is_err());

    assert_eq!(*queue.front().unwrap(), 8);
    let res = queue.dequeue();
    assert!(res.is_ok());
    assert_eq!(*res.unwrap(), 8);

    assert_eq!(*queue.front().unwrap(), 6);
    let res = queue.dequeue();
    assert!(res.is_ok());
    assert_eq!(*res.unwrap(), 6);

    assert_eq!(queue.size(), 6);

    assert_eq!(*queue.dequeue().unwrap(), 26);
    assert_eq!(*queue.dequeue().unwrap(), 29);
    assert_eq!(*queue.dequeue().unwrap(), 2);
    assert_eq!(*queue.dequeue().unwrap(), 9);
    assert_eq!(*queue.dequeue().unwrap(), 7);
    assert_eq!(*queue.dequeue().unwrap(), 22);

    assert!(queue.dequeue().is_err());
}
