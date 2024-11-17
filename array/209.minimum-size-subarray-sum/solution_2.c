    /*
 * @lc app=leetcode id=209 lang=c
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <stdlib.h>
#define min(a, b) ((a < b) ? a : b)

int minSubArrayLen(int target, int* nums, int numsSize) {
    // Find the corresponding left index for each right index with binary search
    // Time: O(NlogN), Space: O(N)
    int minLength = numsSize + 1;
    int *prefix = malloc((numsSize + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 1; i <= numsSize; i++) { // sum 0~i-1
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    for (int i = numsSize; i >= 0 && prefix[i] >= target; i--) {
        int j = 0, k = i; // left index: [0, right index]
        int diff = prefix[i] - target;
        while (j <= k) {
            int mid = j + (k - j) / 2;
            if (prefix[mid] > diff) {
                k = mid - 1; // lower than diff
            } else {
                j = mid + 1; // greater & eqaul to diff
            }
        }
        minLength = min(minLength, i - k);
    }

    return minLength <= numsSize ? minLength : 0;
}
// @lc code=end

