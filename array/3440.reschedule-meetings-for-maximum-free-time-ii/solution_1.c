/*
 * @lc app=leetcode id=3440 lang=c
 *
 * [3440] Reschedule Meetings for Maximum Free Time II
 */

// @lc code=start
#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxFreeTime(int eventTime, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    // Iterate through each event to determine the maximum possible free time after rescheduling.
    // Rescheduling may extend the free interval between adjacent boundaries [left, right]:
    // 1. The event can move into another free slot, freeing the entire boundary interval.
    // 2. Alternatively, shifting the event toward either boundary results in:
    //    freeTime = boundaryLength - eventLength.
    int result = 0, n = startTimeSize;

    bool movable[n];
    for (int i = 0; i < n; i++) {movable[i] = false;}
    
    // Check is event can be rescheduled out of this boundary
    int freeSlotLeft = 0, freeSlotRight = 0;
    for (int i = 0; i < n; i++) {
        // Left to right pass
        if (endTime[i] - startTime[i] <= freeSlotLeft) {movable[i] = true;}
        // Update maximum free time length at the LHS
        freeSlotLeft = max(freeSlotLeft, startTime[i] - ((i > 0) ? endTime[i-1] : 0));

        // Right to left pass
        int rightIdx = n - 1 - i;
        if (endTime[rightIdx] - startTime[rightIdx] <= freeSlotRight) {movable[rightIdx] = true;}
        freeSlotRight = max(freeSlotRight, ((i > 0) ? startTime[rightIdx+1] : eventTime) - endTime[rightIdx]);
    }

    for (int i = 0; i < n; i++) {
        int left = (i > 0) ? endTime[i-1] : 0;
        int right = (i == n - 1) ? eventTime : startTime[i+1];

        if (movable[i]) {
            result = max(result, right - left);
        } else {
            result = max(result, right - left - (endTime[i] - startTime[i]));
        }
    }

    return result;
}
// @lc code=end

