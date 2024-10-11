/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */

// @lc code=start
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // Heap approach, Time: O(N + NlogN + N) = O(NlogN), Space: O(N)
        int len = times.size();
        vector<pair<int,int>> events;
        for (int i = 0; i < len; i++) {
            events.push_back({times[i][0], i}); // arrival
        }
        sort(events.begin(), events.end()); // timeline in order

        // min available chair
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        // {leaving time, chair index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupiedChairs; 

        // all chairs available
        for (int i = 0; i < len; i++) {availableChairs.push(i);}

        for (auto event : events) {
            int time = event.first, index = event.second;
            // for every pair, arrival < leaving 
            // -> there must be a chair occupied when leaving
            while (!occupiedChairs.empty() && time >= occupiedChairs.top().first) { // release chair
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }
            if (time == times[targetFriend][0]) {
                return availableChairs.top();
            }
            // sit on the smallest available chair
            occupiedChairs.push({times[index][1], availableChairs.top()});
            availableChairs.pop();
        }
        return 0;
    }
};
// @lc code=end

