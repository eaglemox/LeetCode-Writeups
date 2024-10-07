/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        // similar to prefix, postfix expression
        // Time: O(N), Space: O(N)
        stack<char> substr;
        char prev = -1;
        for (char c : s) {
            if ((prev == 'A' && c == 'B') || (prev == 'C' && c == 'D')) {
                substr.pop();
            } else {
                substr.push(c);
            }
            prev = (substr.empty()) ? -1 : substr.top();
        }
        int count = 0;
        while (!substr.empty()) {
            substr.pop();
            count++;
        }
        return count;
    }
};
// @lc code=end

