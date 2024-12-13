/*
 * @lc app=leetcode id=2593 lang=c
 *
 * [2593] Find Score of an Array After Marking All Elements
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long long findScore(int* nums, int numsSize) {
    // Brute force simulation -> TLE
    // Time: O(N^2), Space: O(N)
    bool marked[numsSize];
    memset(marked, 0, sizeof(marked));
    int count = 0;
    long long result = 0;
    while (count < numsSize) {
        int minIndex = -1;
        for (int i = 0; i < numsSize; i++) {
            if (marked[i]) {continue;}
            if (minIndex == -1 || nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        result += nums[minIndex];
        marked[minIndex] = true;
        count++;
        if (minIndex > 0 && !marked[minIndex-1]) {
            marked[minIndex-1] = true;
            count++;
        }
        if (minIndex < numsSize - 1 && !marked[minIndex+1]) {
            marked[minIndex+1] = true;
            count++;
        }
    }
    return result;
}
// @lc code=end

