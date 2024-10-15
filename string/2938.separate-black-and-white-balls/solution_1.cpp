/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        int len = s.size();
        long long swapCount = 0;
        int blackCount = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                swapCount += blackCount;
            } else {blackCount++;}
        }
        return swapCount;
    }
};
// @lc code=end

