/*
 * @lc app=leetcode id=371 lang=c
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
int getSum(int a, int b) {
    // Compute whole word until no carry, Time: O(1), Space: O(1)
    int carry = 0;
    while (b != 0) {
        // prevent undefined behavior that trigger runtime error 
        carry = (unsigned int)(a & b) << 1;
        a ^= b; // stay bit of sum
        b = carry; // next iter: a + carry (b)
    }
    return a;
}
// @lc code=end

