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
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < 2 || s[i] != s[j-1] || s[j-1] != s[j-2]) { // Cannot form three consecutive letter
                s[j++] = s[i];
            }
        }

        return s.substr(0, j);
    }
};
// @lc code=end

