/*
 * @lc app=leetcode id=1014 lang=c
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int maxScoreSightseeingPair(int* values, int valuesSize) {
    // The score is the sum of spot values minus the distance between two spot
    // Decrement the maxValue by one each iteration to track the value of values[i] + i - j
    // Time: O(N), Space: O(1)
    int maxScore = 0, maxValue = values[0];
    for (int i = 1; i < valuesSize; i++) {
        maxValue--;
        maxScore = max(maxScore, maxValue + values[i]);
        maxValue = max(maxValue, values[i]);
    }
    return maxScore;
}
// @lc code=end

