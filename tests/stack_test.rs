use algorithm::data_structure::stack::*;

// Stack
#[test]
fn stack_methods_should_handle_data_correctly() {
    let mut stack = stack::Stack::new(8);

    assert!(stack.is_empty());
    assert!(!stack.is_full());
    assert_eq!(stack.size(), 0);

    assert!(stack.push(8).is_ok());
    assert!(stack.push(6).is_ok());
    assert!(stack.push(26).is_ok());
    assert!(stack.push(29).is_ok());
    assert!(stack.push(2).is_ok());
    assert!(stack.push(9).is_ok());
    assert!(stack.push(7).is_ok());
    assert!(stack.push(22).is_ok());

    assert!(!stack.is_empty());
    assert_eq!(stack.size(), 8);
    assert!(stack.is_full());

    assert!(stack.push(19).is_err());

    assert_eq!(*stack.top().unwrap(), 22);
    assert!(stack.pop().is_ok());
    assert_eq!(*stack.pop().unwrap(), 22);

    assert_eq!(*stack.top().unwrap(), 7);
    assert!(stack.pop().is_ok());
    assert_eq!(*stack.pop().unwrap(), 7);

    assert_eq!(stack.size(), 6);

    assert_eq!(*stack.pop().unwrap(), 9);
    assert_eq!(*stack.pop().unwrap(), 2);
    assert_eq!(*stack.pop().unwrap(), 29);
    assert_eq!(*stack.pop().unwrap(), 26);
    assert_eq!(*stack.pop().unwrap(), 6);
    assert_eq!(*stack.pop().unwrap(), 8);

    assert!(stack.pop().is_err());
}
