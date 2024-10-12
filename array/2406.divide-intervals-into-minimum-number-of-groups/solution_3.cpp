/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Heap approach, Time: O(NlogN), Space: O(N)
        sort(intervals.begin(), intervals.end());
        // A min heap stores the right interval of each group
        priority_queue<int, vector<int>, greater<int>> groups;

        for (auto interval : intervals) {
            if (!groups.empty() && groups.top() < interval[0]) {
                // non-overlapping, no new group reqiured
                groups.pop();
            }
            groups.push(interval[1]);
        }
        return groups.size();
    }
};
// @lc code=end

