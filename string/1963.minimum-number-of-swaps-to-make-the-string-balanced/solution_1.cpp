/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        // Time: O(N),  Space: O(1)
        int lbracket = 0, rbracket = 0;
        for (char c : s) {
            if (c == '[') {lbracket++;}
            else {
                if (lbracket) {
                    lbracket--;
                } else {
                    rbracket++;
                }
            }
        }
        // r: #imbalanced brackets, add 1 to ceiling the #swaps
        return (rbracket + 1) / 2;
    }
};
// @lc code=end

