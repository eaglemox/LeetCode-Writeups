/*
 * @lc app=leetcode id=2563 lang=c
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b; 
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    // Two pointer approach, count each left num's possible right num choice
    // Time: O(NlogN), Space: O(1)
    qsort(nums, numsSize, sizeof(int), cmp); // sort in ascending order
    
    int i = 0, j = numsSize - 1, k = numsSize - 1; // i < j <= k
    long long pairCount = 0;
    while (i < k) {
        int lowerDiff = lower - nums[i], upperDiff = upper - nums[i];
        while (k > i && nums[k] > upperDiff) {k--;} // largest num <= upperDiff
        while (j > i + 1 && nums[j-1] >= lowerDiff) {j--;} // smallest num >= lowerDiff
        
        if (j <= k && nums[j] >= lowerDiff && nums[k] <= upperDiff) {
            pairCount += k - j + 1;
        }
        // i increment and j must greater than i (at least i+1)
        if (j < ++i) {j++;}
    }
    return pairCount;
}
// @lc code=end

