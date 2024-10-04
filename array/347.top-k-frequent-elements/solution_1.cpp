/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> map;
        for (int num : nums) {
            map[num]++;
        }
        // max heap: sort using pair.first then pair.second
        priority_queue<pair<int,int>> heap;
        for (auto pair : map) {
            heap.push({pair.second, pair.first}); // <count, num>
        }

        while (k--) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};
// @lc code=end

