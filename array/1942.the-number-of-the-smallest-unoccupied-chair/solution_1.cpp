/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // Time: O(N^2), Space: O(N)
        vector<int> targetTime = times[targetFriend];
        sort(times.begin(), times.end()); // sort by time
        vector<int> occupiedUntilChair(times.size()); // max n chairs occupied
        
        for (vector<int> time : times) {
            for (int i = 0; i < times.size(); i++) { // check smallest available chair
                if (occupiedUntilChair[i] <= time[0]) { // one's leaving time can be other's arrival time
                    occupiedUntilChair[i] = time[1];
                    if (time == targetTime) {return i;}
                    break;
                }

            }
        }

        return 0;
    }
};
// @lc code=end

