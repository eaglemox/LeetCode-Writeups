/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 0) {return result;}
        unordered_map<string, vector<string>> map(strs.size());
        for (string str : strs) {
            int count[26] = {0};
            for (char c : str) {
                count[c-'a']++;
            }
            string temp = "";
            for (int i = 0; i < 26; i++) {
                temp += to_string(count[i]);
                if (i != 25) {temp += "#";}
            }
            map[temp].push_back(str);
        }
        for (auto& pair : map) {
            result.push_back(pair.second);
        }
        return result;
    }
};
// @lc code=end
