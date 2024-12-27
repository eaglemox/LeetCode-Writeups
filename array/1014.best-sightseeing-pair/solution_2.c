/*
 * @lc app=leetcode id=1014 lang=c
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int maxScoreSightseeingPair(int* values, int valuesSize) {
    // Store values[i] + i, values[j] - j, find the max combination of two values
    // Time: O(N), Space: O(1)
    int pair1[valuesSize], pair2[valuesSize];
    for (int i = 0; i < valuesSize; i++) {
        pair1[i] = values[i] + i;
        pair2[i] = values[i] - i;
    }
    int maxScore = 0, maxPair1 = pair1[0];
    for (int i = 0; i < valuesSize - 1; i++) {
        maxPair1 = max(maxPair1, pair1[i]);
        maxScore = max(maxScore, maxPair1 + pair2[i+1]);
    }
    return maxScore;
}
// @lc code=end

