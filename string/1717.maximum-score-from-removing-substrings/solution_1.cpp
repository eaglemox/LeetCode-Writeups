/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int removeSubstr(string& s, const string& pattern, int point) {
        int i, j = 0, points = 0;
        for (i = 0; i < s.size(); i++) {
            s[j++] = s[i];

            if (j > 1 && s[j-2] == pattern[0] && s[j-1] == pattern[1]) {
                j -= 2;
                points += point;
            }
        }

        s = s.substr(0, i + 1); // Trim to new size

        return points;
    }

    int maximumGain(string s, int x, int y) {
        // Greedily remove "ab" or "ba" depending on which yields more points.
        // Removing the higher-value pattern first always leads to an optimal or equal result.
        int result = 0;
        if (x > y) {
            result += removeSubstr(s, "ab", x);
            result += removeSubstr(s, "ba", y);
        } else {
            result += removeSubstr(s, "ba", y);
            result += removeSubstr(s, "ab", x);
        }

        return result;
    }
};
// @lc code=end

