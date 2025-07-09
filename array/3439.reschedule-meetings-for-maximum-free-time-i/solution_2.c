/*
 * @lc app=leetcode id=3439 lang=c
 *
 * [3439] Reschedule Meetings for Maximum Free Time I
 */

// @lc code=start
int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    // Compute the length of free time: (next upper bound - previous adjacent lower bound) - meeting length
    int result = 0, meetingLength = 0;
    for (int i = 0; i < startTimeSize; i++) {
        meetingLength += endTime[i] - startTime[i];
        int lower = (i < k) ? 0 : endTime[i-k];// Add to the window until k free times
        int upper = (i == startTimeSize - 1) ? eventTime : startTime[i+1];
        if (result < upper - lower - meetingLength) {
            result = upper - lower - meetingLength;
        }
        if (i >= k - 1) { // already k meetings
            meetingLength -= endTime[i-k+1] - startTime[i-k+1];
        }
    }

    return result;
}
// @lc code=end

