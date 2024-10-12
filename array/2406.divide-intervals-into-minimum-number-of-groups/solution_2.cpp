/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sweep line approach, Time: O(NlogN), Space: O(2N)
        map<int,int> events;
        for (auto interval : intervals) { // O(logN) insertion
            // the interval is [left, right], [1, 5], [5, 8] are considered intersect
            events[interval[0]]++;
            events[interval[1]+1]--;
        }

        //for (auto event : events) {
        //    printf("%d(%d) ", event.first, event.second);
        //} cout << endl;

        int intersect = 0, maxIntersect = 1;
        for (auto event : events) { // requires maxIntersect groups to divide into non-overlapped intervals
            intersect += event.second;
            maxIntersect = max(maxIntersect, intersect);
        }
        return maxIntersect;
    }
};
// @lc code=end

