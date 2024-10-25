/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        // Compute whole word until no carry, Time: O(1), Space: O(1)
        int carry = 0;
        while (b != 0) {
            carry = (a & b) << 1;
            a ^= b; // stay bit of sum
            b = carry; // next iter: a + carry (b)
        }
        return a;
    }
};
// @lc code=end

