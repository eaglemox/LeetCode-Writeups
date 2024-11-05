/*
 * @lc app=leetcode id=2859 lang=c
 *
 * [2859] Sum of Values at Indices With K Set Bits
 */

// @lc code=start
int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    // Interative counting set bits of each index
    // Time: O(N), Space: O(1)
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (countBits(i) == k) {
            sum += nums[i];
        }
    }
    return sum;
}

int countBits(int num) {
    int count = 0;
    while (num > 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}
// @lc code=end

