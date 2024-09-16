/*
 * @lc app=leetcode id=539 lang=c
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    if (*(int *)a < *(int *)b) {
        return -1;
    } else {
        return 1;
    }
}
int getMinute(char *timePoint) {
    return ((timePoint[0] - '0') * 10 + (timePoint[1] - '0')) * 60 + (timePoint[3] - '0') * 10 + (timePoint[4] - '0');
}
int findMinDifference(char** timePoints, int timePointsSize) {
    int min; // maximum: 00:00 - 12:00 = 720 min
    int minute[timePointsSize];
    for (int i = 0; i < timePointsSize; i++) {
        minute[i] = getMinute(timePoints[i]);
    }
    // sort in ascending order
    qsort(minute, timePointsSize, sizeof(int), cmp);
    // circular difference
    min = minute[timePointsSize-1] - minute[0];
    if (min > 720) {min = 1440 - min;}
    for (int i = 1; i < timePointsSize; i++) {
        int diff = minute[i] - minute[i-1];
        if (diff == 0) {return 0;} 
        if (diff > 720) {diff = 1440 - diff;}
        if (diff < min) {
            min = diff;
        }
    }
    return min;
}
// @lc code=end

