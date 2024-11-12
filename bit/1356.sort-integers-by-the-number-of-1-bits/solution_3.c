/*
 * @lc app=leetcode id=1356 lang=c
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int cmp (const void* a, const void* b) {
    int _a = *(int *)a, _b = *(int *)b;
    int bitsA = countBits(_a), bitsB = countBits(_b);
    if (bitsA == bitsB) {
        return _a - _b;
    } else {
        return bitsA - bitsB;
    }
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    // Quick sort -> qsort(), Time: O(NlogN), Space: O(N)
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), cmp);
    
    return arr;
}
// @lc code=end

