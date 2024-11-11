/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* sortArray(int* nums, int numsSize, int* returnSize) { 
    // Quick sort of stdlib, Time: O(NlogN), Space: O(N)
    *returnSize = numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums;
}
// @lc code=end

