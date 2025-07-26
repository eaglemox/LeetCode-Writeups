/*
 * @lc app=leetcode id=3480 lang=cpp
 *
 * [3480] Maximize Subarrays After Removing One Conflicting Pair
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        // Total count of valid subarrays = #subarray without any conflict pair + #subarray with one conflict pair to be removed
        // Choose the conflict pair with maximum #subarray that can create
        vector<vector<int>> leftBoundary(n + 1);
        for (const auto& pair: conflictingPairs) {
            int l = min(pair[0], pair[1]), r = max(pair[0], pair[1]);
            leftBoundary[r].push_back(l);
        }

        long long result = 0;
        vector<long long> maxLeft = {0, 0};
        vector<long long> gain(n + 1, 0); 
        for (int r = 1; r <= n; r++) {
            // Update maximum conflict left value with current possible conflict pairs
            for (const int& l: leftBoundary[r]) {
                if (l > maxLeft[0]) {
                    maxLeft = {l, maxLeft[0]};
                } else if (l > maxLeft[1]) {
                    maxLeft = {maxLeft[0], l};
                }
            }

            result += r - maxLeft[0];
            if (maxLeft[0] > 0) {
                gain[maxLeft[0]] += maxLeft[0] - maxLeft[1];
            }
        }
        long long maxGain = 0;
        for (const long long& g: gain) {
            maxGain = max(maxGain, g);
        }
        
        return result + maxGain;
    }
};
// @lc code=end

