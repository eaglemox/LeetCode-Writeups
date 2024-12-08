/*
 * @lc app=leetcode id=2054 lang=c
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)

int cmp(const void* a, const void* b) {
    int **_a = (int **)a, **_b = (int **)b;
    if ((*_a)[0] == (*_b)[0]) {
        return (*_a)[1] - (*_b)[1];
    } else {
        return (*_a)[0] - (*_b)[0];
    }
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    // For each event, find its non-overlapping event with largest value
    // Binary search events start after i-th event, find the max value 
    // after such non-overlapping event in constant time using a suffix array
    // Time: O(NlogN), Space: O(N)
    qsort(events, eventsSize, sizeof(int *), cmp);
    int *suffixMax = malloc(eventsSize * sizeof(int));
    suffixMax[eventsSize-1] = events[eventsSize-1][2];
    for (int i = eventsSize - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i+1], events[i][2]);
    }

    int maxValue = 0;
    for (int i = 0; i < eventsSize; i++) {
        // Binary search events start after i-th event
        const int end = events[i][1];
        int sum = events[i][2], left = i + 1, right = eventsSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] <= end) {left = mid + 1;}
            else {right = mid - 1;}
        }
        if (left < eventsSize) {
            sum += suffixMax[left];
        }
        maxValue = max(maxValue, sum);
    }
    return maxValue;
}
// @lc code=end

