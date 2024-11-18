/*
 * @lc app=leetcode id=1486 lang=c
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
int xorOperation(int n, int start) {
    // Time: O(N), Space: O(1)
    int num = start, xorSum = 0;
    for (int i = 0; i < n; i++) {
        xorSum ^= num;
        num += 2;
    }
    return xorSum;
}
// @lc code=end

