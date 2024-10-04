/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 0) {return result;}
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(move(str)); // move to reduce copy cost
        }
        for (auto& pair : map) {
            result.push_back(move(pair.second));
        }
        return result;
    }
};
// @lc code=end
