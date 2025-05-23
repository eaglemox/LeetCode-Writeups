/*
 * @lc app=leetcode id=3068 lang=cpp
 *
 * [3068] Find the Maximum Sum of Node Values
 */

// @lc code=start
#include <stdlib.h>
#include <limits.h>

inline int max(int a, int b) {
    if (a > b) {return a;}
    return b;
}

inline int min(int a, int b) {
    if (a < b) {return a;}
    return b;
}

long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
    long long sum = 0;
    int count = 0, minDiff = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int xored = nums[i] ^ k;
        sum += max(nums[i], xored);
        count ^= (xored > nums[i]);
        minDiff = min(minDiff, abs(nums[i] - xored));
    }

    return sum - (count ? minDiff : 0);
}
// @lc code=end

