/*
 * @lc app=leetcode id=3097 lang=c
 *
 * [3097] Shortest Subarray With OR at Least K II
 */

// @lc code=start
#define min(a, b) ((a < b) ? a : b)

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    // Return length of least subarray of nums that its OR is no less than k
    // We cannot easily find the bit difference before and after a OR operation,
    // utilize sliding window and bin count to track the current window's OR sum value
    // Time: O(N), Space: O(1)
    int start = 0, end = 0;
    int minLength = numsSize + 1;
    int count[32] = {0};
    while (end < numsSize) {
        updateBitCount(&count, nums[end], 1);
        while (start <= end && bitCountToInt(&count) >= k) {
            minLength = min(minLength, end - start + 1);
            updateBitCount(&count, nums[start], -1);
            start++;
        }
        end++;
    }
    return minLength > numsSize ? -1 : minLength;
}

void updateBitCount(int *count, int num, int inc) {
    int bit = 0;
    while (num > 0) {
        count[bit] += inc * (num & 1);
        bit++;
        num >>= 1;
    }
}

int bitCountToInt(int *count) {
    int num = 0;
    for (int i = 0; i < 32; i++) {
        if (count[i]) {
            num |= 1 << i;
        }
    }
    return num;
}
// @lc code=end

