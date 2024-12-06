/*
 * @lc app=leetcode id=2554 lang=c
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    // Sort the banned list then greedly sum the numbers
    // Time: O(NlogN), Space: O(1)
    int count = 0;
    qsort(banned, bannedSize, sizeof(int), cmp);
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if (j < bannedSize && i == banned[j]) {
            // duplicated numbers
            while (j < bannedSize && banned[j] == i) {j++;}
        }
        else if ((maxSum -= i) >= 0) {
            count++;
        }
    }
    return count;
}
// @lc code=end

