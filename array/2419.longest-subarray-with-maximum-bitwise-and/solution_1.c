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
    // Interate once, must check the value of new max is strictly greater than previous 
    int max = 0, length = 0;
    int l = 0, r = 0;
    for (int i = 0; i < numsSize; i++) {
        // printf("current %d: %d\n", i, nums[i]);
        if (max <= nums[i]) {
            length = (max < nums[i]) ? 0 : length;
            max = nums[i];
            l = r = i;
            if (i < numsSize-1) {
                // check i does not exceed boundary
                while(max == nums[i+1]) {
                    r = ++i;
                    if (i == numsSize-1) {break;}
                }
            }
        } 
        length = max(length, (r - l + 1));
        // printf("(%d, %d): %d\n", l, r, length);
    }
    
    return length;
}
// @lc code=end

