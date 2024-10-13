/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue approach, Time: O(Nlogk), Space: O(k)
        // Insertion of PQ costs O(logk) time, worst case insert, pop N times, N = length of specific list [1, 50]
        int k = nums.size();
        vector<int> result = {-100000, 100000}; // max range
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
                       greater<>> queue;
        int maxVal = INT_MIN;
        for (int i = 0; i < k; i++) { // push first k element into pq
            queue.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        while (true) {
            auto [minVal, index] = queue.top(); // structured binding
            if (maxVal - minVal < result[1] - result[0]) { // update range
                result[0] = minVal;
                result[1] = maxVal;
            }

            // break when reach end or pop minimum and push next element on the same list
            int listIdx = index.first, elementIdx = index.second;
            if (++elementIdx == nums[listIdx].size()) {break;}
            else {
                queue.pop();
                queue.push({nums[listIdx][elementIdx], {listIdx, elementIdx}});
                maxVal = max(maxVal, nums[listIdx][elementIdx]);
            }
        }
        return result;
    }
};
// @lc code=end

