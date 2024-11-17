/*
 * @lc app=leetcode id=3095 lang=c
 *
 * [3095] Shortest Subarray With OR at Least K I
 */

// @lc code=start
int bitsToInt(int *bitCount, int bitSize) {
    int result = 0;
    for (int i = 0; i < bitSize; i++) {
        result |= (bitCount[i] > 0);
    }
    return result;
}

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    // Nums are within 6 bits range [0, 63], tracking the bit frequency to
    // compute current OR sum value, Time: O(N), Space: O(6)
    int minLength = numsSize + 1;
    int bitCount[6] = {0};
    
    int i = 0, j = 0;
    while (j < numsSize) {
        for (int bit = 0; bit < 6; bit++) {
            bitCount[bit] += (nums[j] >> bit) & 1;
        }
        while (i <= j && bitsToInt(&bitCount[0], 6) >= k) {
            minLength = min(minLength, j - i + 1);
            for (int bit = 0; bit < 6; bit++) {
                bitCount[bit] -= (nums[i] >> bit) & 1;
            }
            i++;
        }
        j++;
    }
    return (minLength <= numsSize) ? minLength : -1;
}
// @lc code=end