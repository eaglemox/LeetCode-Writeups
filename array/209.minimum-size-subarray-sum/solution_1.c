    /*
 * @lc app=leetcode id=209 lang=c
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <stdlib.h>
#define min(a, b) ((a < b) ? a : b)

int minSubArrayLen(int target, int* nums, int numsSize) {
    // All elements are positive, shrink the length with prefixSum
    // Time: O(N), Space: O(N)
    int minLength = numsSize + 1;
    int *prefix = malloc((numsSize + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 1; i <= numsSize; i++) { // sum 0~i-1
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    int i = 0, j = 1, currentSum;
    while (j <= numsSize) {
        while ((currentSum = prefix[j] - prefix[i]) >= target) {
            minLength = min(minLength, j - i);
            i++;
        }
        j++;
    }

    return minLength <= numsSize ? minLength : 0;
}
// @lc code=end

