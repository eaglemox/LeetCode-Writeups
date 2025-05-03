/*
 * @lc app=leetcode id=1007 lang=c
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    // Count the appearance of values in top or bottom row
    int length = topsSize;
    int countTop[7] = {0}, countBot[7] = {0}, duplicate[7] = {0};
    for (int i = 0; i < length; i++) {
        countTop[tops[i]]++;
        countBot[bottoms[i]]++;
        if (tops[i] == bottoms[i]) {
            duplicate[tops[i]]++;
        }
    }
    // Only one value (if any) can satisfy the condition to fill an entire row
    // Once such a value is found, it guarantees the minimum number of rotations needed
    // 1. The combined count in tops and bottoms (excluding overlaps) equals #dominoes
    // 2. Every domino has the same two values on its two sides
    for (int i = 1; i <= 6; i++) {
        if (countTop[i] + countBot[i] - duplicate[i] == length) {
            return length - ((countTop[i] > countBot[i]) ? countTop[i] : countBot[i]);
        }
    }
    return -1;
}
// @lc code=end

