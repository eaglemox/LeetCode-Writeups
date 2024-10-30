/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if more than one '1' exist -> false
        // Time: O(32), Space: O(1)
        if (n == 0) {return false;}
        int count = 0;
        while (n) {
            count += n & 1;
            if (count > 1) {return false;}
            n >>= 1;
        }
        return true;
    }
};
// @lc code=end

