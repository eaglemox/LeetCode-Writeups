/*
 * @lc app=leetcode id=868 lang=c
 *
 * [868] Binary Gap
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int binaryGap(int n) {
    // Record the distance after read a set bit from LSB
    // Time: O(32), Space: O(1)
    int distance = -1, maxDistance = 0;
    while (n > 0) {
        if (n & 1) {
            maxDistance = max(maxDistance, distance);
            distance = 1;
        } else if (distance != -1) {distance++;}
        n >>= 1;
    }
    return maxDistance;
}
// @lc code=end

