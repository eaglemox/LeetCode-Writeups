/*
 * @lc app=leetcode id=2044 lang=c
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
int countMaxOrSubsets(int* nums, int numsSize) {
    // Find number of subsets which OR sum is OR sum of original array
    int maxOR = 0;
    for (int i = 0; i < numsSize; i++) {
        maxOR |= nums[i];
    }
    return countSubsets(nums, numsSize, 0, 0, maxOR);
}

int countSubsets(int* nums, int numsSize, int index, int currOR, int targetOR) {
    // Recursively select whether adding numbers to the subset
    if (index == numsSize) {return currOR == targetOR;} // Reach end of array
    int selected = countSubsets(nums, numsSize, index + 1, currOR | nums[index], targetOR);
    int notselected = countSubsets(nums, numsSize, index + 1, currOR, targetOR);
    return selected + notselected;
}
// @lc code=end

