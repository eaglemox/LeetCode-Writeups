/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int len = s.size();
        string result = "";
        result.push_back(s[0]);
        for (int i = 1, cnt = 1; i < len; i++) {
            if (s[i] == result.back()) { // Same letter
                cnt++;
                if (cnt >= 3) {continue;}
            } else {
                cnt = 1; // Reset count
            }
            result.push_back(s[i]);
        }

        return result;
    }
};
// @lc code=end

