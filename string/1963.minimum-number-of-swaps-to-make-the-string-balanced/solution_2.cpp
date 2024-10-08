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
        // Reduce number of variables, though we count the '[' not ']'
        // the point is to track the number of brackets remains unclosed
        // Time: O(N), Space: O(1)
        int imbalance = 0;
        for (char c : s) {
            if (c == '[') {imbalance++;}
            else if (imbalance) {imbalance--;}
        }
        // add 1 to ceiling the #swaps
        return (imbalance + 1) / 2;
    }
};
// @lc code=end

