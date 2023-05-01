use algorithm::data_structure::heap::heap::*;
use algorithm::data_structure::heap::max_heap::*;
use algorithm::data_structure::heap::min_heap::*;
use algorithm::data_structure::heap::HeapError;

#[test]
fn test_integer_min_heap_basic_functionality() {
    let mut heap = MinHeap::new(Some(11));

    assert_eq!(heap.size(), 0);
    assert_eq!(heap.is_empty(), true);
    assert_eq!(heap.is_full(), false);

    assert!(matches!(heap.insert(6), Ok(())));
    assert!(matches!(heap.insert(8), Ok(())));
    assert!(matches!(heap.insert(10), Ok(())));
    assert!(matches!(heap.insert(26), Ok(())));
    assert!(matches!(heap.insert(9), Ok(())));

    assert_eq!(heap.size(), 5);
    assert_eq!(heap.is_empty(), false);
    assert_eq!(heap.is_full(), false);

    assert!(matches!(heap.insert(2), Ok(())));
    assert!(matches!(heap.insert(40), Ok(())));
    assert!(matches!(heap.insert(22), Ok(())));
    assert!(matches!(heap.insert(6), Ok(())));
    assert!(matches!(heap.insert(32), Ok(())));
    assert!(matches!(heap.insert(3), Ok(())));

    assert_eq!(heap.size(), 11);
    assert_eq!(heap.is_empty(), false);
    assert_eq!(heap.is_full(), true);

    println!("{}", heap);

    assert!(matches!(heap.insert(18), Err(HeapError::HeapOverflowError)));

    assert!(matches!(heap.remove(5), Ok(10)));
    assert!(matches!(heap.remove(2), Ok(6)));
    assert!(matches!(heap.remove(3), Ok(8)));
    assert!(matches!(heap.remove(1), Ok(3)));

    assert_eq!(heap.size(), 7);
    assert_eq!(heap.is_empty(), false);
    assert_eq!(heap.is_full(), false);

    assert!(matches!(heap.remove(0), Ok(2)));
    assert!(matches!(heap.remove(2), Ok(9)));
    assert!(matches!(heap.remove(1), Ok(22)));

    assert!(matches!(
        heap.remove(8),
        Err(HeapError::HeapInvalidIndexError)
    ));

    assert!(matches!(heap.remove(0), Ok(6)));
    assert!(matches!(heap.remove(0), Ok(26)));
    assert!(matches!(heap.remove(0), Ok(32)));
    assert!(matches!(heap.remove(0), Ok(40)));

    assert!(matches!(heap.remove(0), Err(HeapError::HeapUnderflowError)));

    assert_eq!(heap.size(), 0);
    assert_eq!(heap.is_empty(), true);
    assert_eq!(heap.is_full(), false);
}

#[test]
fn test_integer_max_heap_basic_functionality() {
    let mut heap = MaxHeap::new(Some(11));

    assert_eq!(heap.size(), 0);
    assert_eq!(heap.is_empty(), true);
    assert_eq!(heap.is_full(), false);

    assert!(matches!(heap.insert(6), Ok(())));
    assert!(matches!(heap.insert(8), Ok(())));
    assert!(matches!(heap.insert(10), Ok(())));
    assert!(matches!(heap.insert(26), Ok(())));
    assert!(matches!(heap.insert(9), Ok(())));

    assert_eq!(heap.size(), 5);
    assert_eq!(heap.is_empty(), false);
    assert_eq!(heap.is_full(), false);

    assert!(matches!(heap.insert(2), Ok(())));
    assert!(matches!(heap.insert(40), Ok(())));
    assert!(matches!(heap.insert(22), Ok(())));
    assert!(matches!(heap.insert(6), Ok(())));
    assert!(matches!(heap.insert(32), Ok(())));
    assert!(matches!(heap.insert(3), Ok(())));

    assert_eq!(heap.size(), 11);
    assert_eq!(heap.is_empty(), false);
    assert_eq!(heap.is_full(), true);

    println!("{}", heap);

    assert!(matches!(heap.insert(18), Err(HeapError::HeapOverflowError)));

    assert!(matches!(heap.remove(5), Ok(2)));
    assert!(matches!(heap.remove(2), Ok(26)));
    assert!(matches!(heap.remove(3), Ok(10)));
    assert!(matches!(heap.remove(1), Ok(32)));

    assert_eq!(heap.size(), 7);
    assert_eq!(heap.is_empty(), false);
    assert_eq!(heap.is_full(), false);

    assert!(matches!(heap.remove(0), Ok(40)));
    assert!(matches!(heap.remove(2), Ok(9)));
    assert!(matches!(heap.remove(1), Ok(8)));

    assert!(matches!(
        heap.remove(8),
        Err(HeapError::HeapInvalidIndexError)
    ));

    assert!(matches!(heap.remove(0), Ok(22)));
    assert!(matches!(heap.remove(0), Ok(6)));
    assert!(matches!(heap.remove(0), Ok(6)));
    assert!(matches!(heap.remove(0), Ok(3)));

    assert!(matches!(heap.remove(0), Err(HeapError::HeapUnderflowError)));

    assert_eq!(heap.size(), 0);
    assert_eq!(heap.is_empty(), true);
    assert_eq!(heap.is_full(), false);
}
