/*
 * @lc app=leetcode id=3439 lang=c
 *
 * [3439] Reschedule Meetings for Maximum Free Time I
 */

// @lc code=start
int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    // We can only reschedule meetings in-place, so gaps between meetings are fixed.
    // This reduces the problem into a sliding window problem: find the largest sum of k consecutive free times.
    // Note: skip the first free time if it’s zero, since it doesn't require rescheduling.
    // startTime and endTime are sorted and non-overlapping.
    int result = 0, currentSum = 0;
    int freeTime[startTimeSize+1];
    
    // Precompute all free time length
    freeTime[0] = startTime[0] - 0;
    for (int i = 1; i < startTimeSize; i++) {
        freeTime[i] = startTime[i] - endTime[i-1];
    }
    freeTime[startTimeSize] = eventTime - endTime[startTimeSize-1];

    // First k free times, if startTime[0] is 0 the first free time is (endTime[0], startTime[1]]
    int startIdx = (startTime[0] == 0);
    for (int i = startIdx; i <= startIdx + k && i <= startTimeSize; i++) {
        currentSum += freeTime[i];
    }

    result = currentSum;

    for (int i = startIdx + k + 1; i < startTimeSize + 1; i++) {
        currentSum += freeTime[i] - freeTime[i-k-1];
        if (currentSum > result) {
            result = currentSum;
        }
    }

    return result;
}
// @lc code=end

