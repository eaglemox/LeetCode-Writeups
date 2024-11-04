/*
 * @lc app=leetcode id=461 lang=c
 *
 * [461] Hamming Distance
 */

// @lc code=start
int hammingDistance(int x, int y) {
    // Time: O(32), Space: O(2)
    int distance = 0, diff = x ^ y;
    while (diff > 0) {
        if (diff & 1) {
            distance++;
        }
        diff >>= 1;
    }
    return distance;
}
// @lc code=end

