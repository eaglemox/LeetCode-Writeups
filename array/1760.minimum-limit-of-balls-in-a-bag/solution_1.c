/*
 * @lc app=leetcode id=1760 lang=c
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int minimumSize(int* nums, int numsSize, int maxOperations) {
    // Binary search the operation count for each limit bag size
    // Find the lowerbound (minSize of maxOperation) within the operation limit
    // Time: O(NlogN), Space: O(1)
    int maxSize = nums[0];
    for (int i = 1; i < numsSize; i++) {
        maxSize = max(maxSize, nums[i]);
    }
    int left = 1, right = maxSize;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int operations = 0;
        for (int i = 0; i < numsSize; i++) {
            // division operation when bag size "larger" than the size limit
            operations += (nums[i] - 1) / mid;
        }
        if (operations > maxOperations) {left = mid + 1;}
        else {right = mid - 1;}
    }
    return left;
}
// @lc code=end

