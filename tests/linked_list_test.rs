use algorithm::data_structure::linked_list::*;

// Singly linked list
#[test]
fn singly_linked_list_methods_should_handle_data_correctly() {
    let mut list = slinked_list::SLinkedList::new();

    assert!(list.is_empty());
    assert_eq!(list.size(), 0);

    list.insert(8);
    list.insert(12);
    list.insert(6);
    list.insert(10);

    assert!(!list.is_empty());
    assert_eq!(list.size(), 4);

    assert!(list.search(8));
    assert!(!list.search(9));

    assert!(list.remove(10).is_ok());
    assert_eq!(list.size(), 3);
    assert!(list.remove(6).is_ok());
    assert_eq!(list.size(), 2);

    assert!(list.remove(9).is_err());
    assert_eq!(list.size(), 2);
}
