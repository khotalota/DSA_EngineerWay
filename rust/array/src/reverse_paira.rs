#[allow(dead_code)]
pub fn reverse_pairs() -> i32 {
    let nums = [1, 3, 2, 3, 1];
    let mut count = 0;
    let len = nums.len();
    for i in 0..len {
        for j in (i + 1)..len {
            if nums[i] > 2 * nums[j] {
                count += 1;
            }
        }
    }
    count
}
