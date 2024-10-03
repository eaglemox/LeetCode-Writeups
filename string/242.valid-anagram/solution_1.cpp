/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;
        for (char c : s) {
            count[c]++;
        }
        for (char c: t) {
            count[c]--;
            if (count[c] == 0) {count.erase(c);}
        }
        return count.empty();
    }
};
// @lc code=end
