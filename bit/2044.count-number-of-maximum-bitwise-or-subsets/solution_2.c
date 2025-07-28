/*
 * @lc app=leetcode id=2044 lang=c
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
int countSubsets(int* nums, int numsSize, int index, int currOR, int targetOR) {
    int count = (currOR == targetOR);
    
    for (int i = index + 1; i < numsSize; i++) {
        count += countSubsets(nums, numsSize, i, currOR | nums[i], targetOR);
    }
    
    return count;
}

int countMaxOrSubsets(int* nums, int numsSize) {
    // Find number of subsets which OR sum is OR sum of original array
    int maxOR = 0, result = 0;
    for (int i = 0; i < numsSize; i++) {
        maxOR |= nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        // Number of subsets starting from i
        result += countSubsets(nums, numsSize, i, nums[i], maxOR);
    }

    return result;
}
// @lc code=end