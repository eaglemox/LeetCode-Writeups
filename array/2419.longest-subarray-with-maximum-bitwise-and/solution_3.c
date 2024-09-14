/*
 * @lc app=leetcode id=2419 lang=c
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
#define max(a,b) (((a) > (b)) ? (a) : (b))
int longestSubarray(int* nums, int numsSize) {
    int maxVal = 0;
    int currLength = 0, maxLength = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            currLength = 0;
            maxLength = 0;
        }
        // if not maxVal, reset currLength
        currLength = (maxVal == nums[i]) ? currLength + 1 : 0;
        maxLength = max(maxLength, currLength);
    }
    
    return maxLength;
}
// @lc code=end