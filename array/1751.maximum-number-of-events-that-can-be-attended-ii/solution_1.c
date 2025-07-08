/*
 * @lc app=leetcode id=1751 lang=c
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    int *_a = *(int**)a, *_b = *(int**)b;
    return _a[0] - _b[0];
}

int search(int** dp, int** events, int eventsSize, int eventIdx, int remains) {
    // Base case
    if (eventIdx == eventsSize || remains == 0) {return 0;}

    // The value is definite by the 
    if (dp[eventIdx][remains] != -1) {return dp[eventIdx][remains];}
    
    // Perform binary search to find next attendable event if we attend current event
    int nextEvent = eventIdx + 1, upper = eventsSize - 1;
    int end = events[eventIdx][1];
    while (nextEvent <= upper) {
        int mid = (nextEvent + upper) / 2;
        if (events[mid][0] > end) { // nextEvent at least end + 1
            upper = mid - 1;
        } else {
            nextEvent = mid + 1;
        }
    }

    int choose = events[eventIdx][2] + search(dp, events, eventsSize, nextEvent, remains - 1);
    int skip = search(dp, events, eventsSize, eventIdx + 1, remains);

    return dp[eventIdx][remains] = (choose > skip) ? choose : skip;
}

int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
    // Use DP to track the maximum value obtainable starting from events[i] with j selections remaining
    int **dp = malloc(eventsSize * sizeof(int*));

    for (int i = 0; i < eventsSize; i++) {
        dp[i] = malloc((k + 1) * sizeof(int));
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1;
        }
    }

    qsort(events, eventsSize, sizeof(int**), cmp);

    return search(dp, events, eventsSize, 0, k);
}
// @lc code=end

