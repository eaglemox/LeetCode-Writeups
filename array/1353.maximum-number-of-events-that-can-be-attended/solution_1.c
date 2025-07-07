/*
 * @lc app=leetcode id=1353 lang=c
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
#include <stdlib.h>
#define MAX_VAL 100000

int find(int* parent, int x) {
    if (parent[x] != x) { // Recursively find root
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

int cmp(const void* a, const void* b) {
    int *_a = *(int**)a, *_b = *(int**)b;
    return _a[1] - _b[1];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    // Sort the event array in ascending order then greedily pick attendable events
    int result = 0;
    qsort(events, eventsSize, sizeof(int**), cmp);

    int lastDay = events[eventsSize-1][1];
    int *parent = malloc((lastDay + 2) * sizeof(int));
    for (int i = 0; i <= lastDay + 1; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < eventsSize; i++) {
        int start = events[i][0], end = events[i][1];
        int availableDay = find(parent, start);
        if (availableDay <= end) {
            // Mark the day as occupied
            parent[availableDay] = find(parent, availableDay + 1);
            result++;
        }
    }

    return result;
}
// @lc code=end

