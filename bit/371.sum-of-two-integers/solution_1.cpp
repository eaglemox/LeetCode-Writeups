/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        // My brain dead approach, Time: O(32), Space: O(5)
        // One bit per interate, simple but potential of bit manipulation is wasted
        int bitA, bitB, sum = 0;
        for (int i = 0, carry = 0; i < 32; i++) { // int: 32-bits
            bitA = a & (1 << i); // current bit of a
            bitB = b & (1 << i); // current bit of b
            sum |= (bitA ^ bitB ^ carry);
            carry = ((bitA & (bitB | carry)) | (bitB & carry)) << 1;
        }
        return sum;
    }
};
// @lc code=end

