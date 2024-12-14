/*
 * @lc app=leetcode id=2762 lang=c
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

long long continuousSubarrays(int* nums, int numsSize){
    // Two pointer sliding window approach
    // Time: O(N), Space: O(1)
    long long windowSize, count = numsSize; // subarrays of size 1
    int i = 0, j = 0, subMin, subMax;
    subMin = subMax = nums[i];
    for (j = 0; j < numsSize; j++) {
        subMin = min(subMin, nums[j]);
        subMax = max(subMax, nums[j]);
        if (subMax - subMin > 2) {
            windowSize = j - i;
            count += (windowSize - 1) * windowSize / 2; // sum: 1,2,3,...,j-i-1
            i = j; // start from j
            subMin = subMax = nums[i];
            while (i > 0 && abs(nums[j] - nums[i-1]) <= 2) {
                i--;
                subMin = min(subMin, nums[i]);
                subMax = max(subMax, nums[i]);
            }
            if (i < j) { // overlapped subarrays with previous window
                windowSize = j - i;
                count -= (windowSize - 1) * windowSize / 2;
            }
        }
    }
    // windows with j reach end
    windowSize = j - i;
    count += (windowSize - 1) * windowSize / 2;
    return count;
}
// @lc code=end

