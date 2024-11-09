/*
 * @lc app=leetcode id=868 lang=c
 *
 * [868] Binary Gap
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int binaryGap(int n) {
    // Record the distance after read a set bit from LSB
    // Without modifying input n
    // Time: O(32), Space: O(1)
    int prevPos = 32, maxDistance = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1U << i)) {
            maxDistance = max(maxDistance, i - prevPos);
            prevPos = i;
        }
    }
    return maxDistance;
}
// @lc code=end

