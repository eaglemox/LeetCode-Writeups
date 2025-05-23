/*
 * @lc app=leetcode id=3068 lang=cpp
 *
 * [3068] Find the Maximum Sum of Node Values
 */

// @lc code=start
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // The edge is a lie
        // If XOR count is even -> fine
        //    XOR count is odd  -> one XOR operation must be undo -> find the operation with least impact
        long long sum = 0;
        int count = 0, minDiff = INT_MAX;
        for (int &num : nums) {
            int xored = num ^ k;
            sum += max(xored, num);
            count ^= (xored > num); // XOR operation make bigger sum
            /*
            if (xored > num) {
                minDiff = min(minDiff, xored - num);
            } else {
                minDiff = min(minDiff, num - xored);
            }
            */
            minDiff = min(minDiff, abs(num - xored));
        }
        return sum - (count ? minDiff : 0);
    }
};
// @lc code=end

