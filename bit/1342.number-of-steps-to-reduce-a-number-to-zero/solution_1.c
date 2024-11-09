/*
 * @lc app=leetcode id=1342 lang=c
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
int numberOfSteps(int num) {
    // The number is odd: last bit is set
    // Time: O(logN), Space: O(1)
    int steps = 0;
    while (num > 0) {
        steps += num & 1; // subtraction
        if (num > 1) {steps++;} // division
        num >>= 1;
    }
    return steps;
}
// @lc code=end

