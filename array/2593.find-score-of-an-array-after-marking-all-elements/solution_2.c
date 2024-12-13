/*
 * @lc app=leetcode id=2593 lang=c
 *
 * [2593] Find Score of an Array After Marking All Elements
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int value;
    int index;
} IndexMap;

int cmp(const void* a, const void* b) {
    IndexMap *_a = (IndexMap *)a, *_b = (IndexMap *)b;
    return _a->value - _b->value;
}

long long findScore(int* nums, int numsSize) {
    // Sorting and tracking the indices
    // Time: O(NlogN), Space: O(N)
    IndexMap map[numsSize];
    for (int i = 0; i < numsSize; i++) {
        map[i].value = nums[i];
        map[i].index = i;
    }
    qsort(map, numsSize, sizeof(IndexMap), cmp);

    bool marked[numsSize];
    memset(marked, 0, sizeof(marked));

    long long result = 0;
    for (int i = 0; i < numsSize; i++) {
        int idx = map[i].index;
        if (marked[idx]) {continue;}
        result += map[i].value;
        if (idx > 0) {
            marked[idx-1] = true;
        }
        if (idx < numsSize - 1) {
            marked[idx+1] = true;
        }
    }
    return result;
}
// @lc code=end

