/*
 * @lc app=leetcode id=2275 lang=c
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int largestCombination(int* candidates, int candidatesSize) {
    // Count the number of candidates with certain bit set 
    // Candidates [1, 1e7] -> within 24 bits range 2^24 = 16777216
    // Time: O(24*N) = O(N), Space: O(1)
    int bitFrequency, maxFrequency = 0;
    for (int bit = 0; bit < 24; bit++) {
        bitFrequency = 0;
        for (int i = 0; i < candidatesSize; i++) {
            bitFrequency += ((candidates[i] >> bit) & 1);
        }
        maxFrequency = max(maxFrequency, bitFrequency);
    }
    return maxFrequency;
}
// @lc code=end

