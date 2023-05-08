use algorithm::data_structure::hashing::*;

#[test]
fn test_integer_hash_table_basic_functionality() {
    let mut map: open_addressing::HashTable<&str, i32> = Default::default();

    assert_eq!(map.size(), 0);
    assert_eq!(map.is_empty(), true);

    assert!(matches!(map.insert("Otter", 29), Ok(())));
    assert!(matches!(map.insert("Dog", 45), Ok(())));
    assert!(matches!(map.insert("Cat", 67), Ok(())));
    assert!(matches!(map.insert("Hamster", 31), Ok(())));

    assert_eq!(map.size(), 4);
    assert_eq!(map.is_empty(), false);

    assert!(matches!(
        map.insert("Otter", 29),
        Err(HashTableError::HashTableKeyAlreadyExistError)
    ));

    let key_list = vec!("Otter", "Dog", "Cat", "Hamster");
    assert!(map.keys().iter().all(|a| key_list.contains(a)));

    assert!(matches!(map.get(&"Otter"), Ok(29)));
    assert!(matches!(map.get(&"Hamster"), Ok(31)));

    assert!(matches!(map.remove("Otter"), Ok(("Otter", 29))));
    assert!(matches!(map.remove("Dog"), Ok(("Dog", 45))));

    assert_eq!(map.size(), 2);
    assert_eq!(map.is_empty(), false);

    assert!(matches!(map.remove("Cat"), Ok(("Cat", 67))));
    assert!(matches!(map.remove("Hamster"), Ok(("Hamster", 31))));

    assert_eq!(map.size(), 0);
    assert_eq!(map.is_empty(), true);

    assert!(matches!(
        map.remove("Cat"),
        Err(HashTableError::HashTableKeyNotExistError)
    ));
}
