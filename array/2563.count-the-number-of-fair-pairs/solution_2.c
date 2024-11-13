/*
 * @lc app=leetcode id=2563 lang=c
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b; 
}

long long countLessPairs(int* nums, int numsSize, int bound) {
    long long pairCount = 0;
    int i = 0, j = numsSize - 1;
    while (i < j) {
        int boundDiff = bound - nums[i];
        while (j > i && nums[j] > boundDiff) {j--;}
        pairCount += j - i;
        i++;
    }
    return pairCount;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    // Two pointer approach, compute the difference of count less than upper and lower
    // Time: O(NlogN), Space: O(1)
    qsort(nums, numsSize, sizeof(int), cmp); // sort in ascending order

    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    } printf("\n");
    
    return countLessPairs(nums, numsSize, upper) - countLessPairs(nums, numsSize, lower - 1);
}
// @lc code=end

