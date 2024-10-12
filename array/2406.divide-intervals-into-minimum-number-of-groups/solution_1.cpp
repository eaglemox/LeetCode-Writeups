/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sweep line approach, Time: O(NlogN), Space: O(2N)
        vector<pair<int,int>> events;
        for (auto interval : intervals) {
            events.push_back({interval[0],1}); // left
            // the interval is [left, right], [1, 5], [5, 8] are considered intersect
            events.push_back({interval[1] + 1,-1}); // right
        }
        sort(events.begin(), events.end());

        int intersect = 0, maxIntersect = 1;
        for (auto event : events) { // requires maxIntersect groups to divide into non-overlapped intervals
            intersect += event.second;
            maxIntersect = max(maxIntersect, intersect);
        }
        return maxIntersect;
    }
};
// @lc code=end

