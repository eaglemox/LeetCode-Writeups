/*
 * @lc app=leetcode id=2894 lang=cpp
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m) { // not divisible
                num1 += i;
            } else {
                num2 += i;
            }
        }
        
        return num1 - num2;
    }
};
// @lc code=end

