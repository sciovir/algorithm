/// Bubble Sort is mainly useful when sorting a large set of floating point
/// numbers which are in range [0, 1). It works by distributing elements to
/// buckets, then sorts each bucket and finally concatenates all sorted buckets.
/// Examples:
/// - Giving an array [0.52, 0.12, 0.86, 0.29, 0.46, 0.4, 0.18, 0.6], 10 buckets
/// and assuming that we sort the array by ascending order.
/// - Distributing all the elements to corresponding buckets by multiplying the
/// element and buckets' slots. Each bucket is a linked list. [0.52, 0.12, 0.86,
/// 0.29, 0.46, 0.4, 0.18, 0.6] -> array
///   [[], [], [], [], [], [], [], [], [], []] -> buckets
///   [0 []
///    1 [] -> [0.12] -> [0.18]   0.12 * 10 = 1.2, 0.18 * 10 = 1.8
///    2 [] -> [0.29]   0.29 * 10 = 2.9
///    3 []
///    4 [] -> [0.46] -> [0.4]   0.46 * 10 = 4.6, 0.4 * 10 = 4.0
///    5 [] -> [0.52]   0.52 * 10 = 5.2
///    6 [] -> [0.6]
///    7 []
///    8 [] -> [0.86]   0.86 * 10 = 8.6
///    9 []
///    ]
/// - We sort each bucket using insertion sort.
/// [[], [0.12, 0.18], [0.29], [], [0.4, 0.46], [0.52], [0.6], [], [0.86], []]
/// - Concatenating all non-empty buckets, array is now sorted.
pub fn sort(array: &mut [f32]) {
    assert!(array.iter().all(|&e| e >= 0.0 && e < 1.0));

    const SLOTS: usize = 10;
    let mut buckets: [Vec<f32>; SLOTS] = Default::default();

    for i in 0..array.len() {
        let bucket_index: usize = (array[i] * SLOTS as f32) as usize;
        println!("{}", bucket_index);
        buckets[bucket_index].push(array[i]);
    }

    let mut index: usize = 0;
    for i in 0..SLOTS {
        buckets[i].sort_by(|a, b| a.partial_cmp(b).unwrap());
        for (_, &v) in buckets[i].iter().enumerate() {
            array[index] = v;
            index += 1;
        }
    }
}
