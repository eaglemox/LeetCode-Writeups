/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, right = 0; // count the incomplete parentheses
        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (left > 0) {
                left--;
            } else {
                right++;
            }
        }
        return left + right;
    }
};
// @lc code=end

