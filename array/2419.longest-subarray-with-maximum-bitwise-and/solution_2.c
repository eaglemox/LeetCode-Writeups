/*
 * @lc app=leetcode id=2419 lang=c
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
// #include <stdio.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
int longestSubarray(int* nums, int numsSize) {
    // for any int A and B, A & B = min(A, B) < max(A, B) if A != B
    // Find maximum value first then find its length of longest subarray
    int max = 0, length = 0;
    for (int i = 0; i < numsSize; i++) {
        max = max(max, nums[i]);
    }
    // printf("maximum value: %d\n", max);

    for (int i = 0; i < numsSize; i++) {
        // printf("current %d: %d\n", i, nums[i]);
        int currentLength = 0;
        if (nums[i] == max) {
            currentLength = 1;
            if (i < numsSize - 1) {
                while(nums[i+1] == max) {
                    currentLength++;
                    // printf("finding subarray: %d, len: %d\n", nums[i], currentLength);
                    i++;
                    if (i == numsSize - 1) {break;}
                }
            }
        }
        length = max(length, currentLength);
    }
    
    return length;
}
// @lc code=end

