#[allow(dead_code)]
pub fn find_max_consecutive_ones() -> i32 {
    let nums = [1, 1, 0, 1, 1, 1];
    let mut max_count = 0;
    let mut current_count = 0;

    for &val in nums.iter() {
        if val == 1 {
            current_count += 1;
            if current_count > max_count {
                max_count = current_count;
            }
        } else {
            current_count = 0;
        }
    }
    max_count
}
