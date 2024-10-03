/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        // only lowercase letters
        for (char c : s) {
            count[c-'a']++;
        }
        for (char c : t) {
            count[c-'a']--;
        }
        for (int val : count) {
            if (val != 0) {return false;}
        }
        return true;
    }
};
// @lc code=end
