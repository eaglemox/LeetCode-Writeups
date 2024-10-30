/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Not loops, check all bits simultaneously, 
        // check if n and n-1 do not intersect 
        // Time: O(1), Space: O(1)
        /* Power of two only have its MSB bit set 
        // -> n-1: the MSB will be cleared and latter bits will be set
        //    34 = 0b100010 
        // -> 33 = 0b100001
        //    16 = 0b10000
        // -> 15 = 0b01111
        */
        return n > 0 && !(n & n - 1);
    }
};
// @lc code=end

