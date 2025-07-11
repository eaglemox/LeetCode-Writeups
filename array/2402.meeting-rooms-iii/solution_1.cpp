/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort start time of the meetings array in ascending order and track the available room using min heap 
        // 1. Book the available room with least room index
        // 2. Delay the meeting until any room is available
        // 3. Meeting with earlier startTime take the available room first
        int count[101] = {};

        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> availableRoom;
        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long, int>>> busyRoom;

        for (int i = 0; i < n; i++) {
            availableRoom.push(i);
        }

        for (auto &meeting: meetings) {
            while (!busyRoom.empty() && busyRoom.top().first <= meeting[0]) { // Skip to current meeting start
                availableRoom.push(busyRoom.top().second);
                busyRoom.pop();
            }
            long long start = availableRoom.empty() ? busyRoom.top().first : meeting[0];
            int length = meeting[1] - meeting[0];
            int roomIdx = availableRoom.empty() ? busyRoom.top().second : availableRoom.top();
            
            if (availableRoom.empty()) {
                busyRoom.pop();
            } else {
                availableRoom.pop();
            }

            count[roomIdx]++;
            busyRoom.push({start + length, roomIdx});
        }

        int result = 0, maxCount = count[0];
        for (int i = 1; i <= 100; i++) {
            if (maxCount < count[i]) {
                maxCount = count[i];
                result = i;
            }
        }

        return result;
    }
};
// @lc code=end

