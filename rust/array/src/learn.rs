#[allow(dead_code)]
const ARR: [i32; 3] = [100, 200, 300];

pub fn learn_hello() {
    println!("Hello, world!");
}

pub fn learn_string() {
    let s: &str = "Hello from sliced string"; //String Literals
    println!("{}", s);

    let mut s1 = String::from("Hello ");
    s1.push_str("from mutable string");
    println!("{}", s1);

    let mut s2 = String::new();
    s2.push_str("Hello from mutable string with new() funtion");
    println!("{}", s2);
}

pub fn learn_array() {
    let arr: &[i32] = &[1, 2, 3, 4, 5, 6];
    let arr2: [i32; 5] = [1, 2, 3, 4, 5]; //array declaring
    println!("{:?}", arr);
    println!("{:#?}", arr2);

    let arr3 = [3; 5];
    println!("{:?}", arr3); //default initialization

    println!("first element: {}", arr2[0]); //element access
    println!("first element: {}", arr2[1]);

    for elem in arr2.iter() {
        print!("{} ", elem);
    }
    println!("\nArray length:{}", arr.len());

    let matrix: [[i32; 3]; 2] = [[1, 2, 3], [4, 5, 6]];
    println!("{:?}", matrix);

    for row in matrix.iter() {
        println!("{:?}", row);
    }

    let slice: &[i32] = &arr2[1..4]; //slicing
    println!("{:?}", slice);

    let mut arr4 = [12, 13, 14, 15];
    arr4[2] = 15;
    println!("{:?}", arr4);

    println!("{:?}", ARR);

    let arr5 = [1, 2, 3];
    let doubled: Vec<i32> = arr5.into_iter().map(|x| x * 2).collect();
    println!("{:?}", doubled);

    let arr6 = [0; 1000];
    println!("{}", arr6[0]);

    let [fi, se, th] = arr5; //array destructuring
    println!("{} {} {}", fi, se, th);

    match arr5 {
        [1, _, 2] => println!("Pattern matched!"), //Pattern matching
        _ => println!("No match"),
    }
}
