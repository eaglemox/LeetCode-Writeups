/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Time: O(N + N + k) = O(N) ???
        vector<int> result;
        map<int,int> count;
        vector<vector<int>> map(nums.size() + 1); // count from 1~N, 0 count doesn't matter
        for (int num : nums) {
            count[num]++;
        }
        // <key, count> -> <count, keys>
        for (auto pair : count) {
            map[pair.second].push_back(pair.first);
        }
        // iterate backward from max count
        for (int i = map.size() - 1; i > 0; i--) {
            for (int num : map[i]) { // keys of same count
                result.push_back(num);
                if (result.size() == k) {return result;}
            }
        }
        return result;
    }
};
// @lc code=end

