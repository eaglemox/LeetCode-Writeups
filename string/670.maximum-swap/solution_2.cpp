/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // can only swap once
        // -> swap first digit about to increase and the max digit (last if multiple) after it
        // Time: O(8), Space: O(8)
        string digits = to_string(num);
        int len = digits.size();
        vector<int> rightmaxIndex(len); // {index: index of rhs max}
        rightmaxIndex[len-1] = len - 1; // boundary condition
        for (int i = len - 2; i >= 0; i--) {
            rightmaxIndex[i] = (digits[i] > digits[rightmaxIndex[i+1]]) ? i : rightmaxIndex[i+1];
        }
        for (int i = 0; i < len; i++) {
            if (digits[i] < digits[rightmaxIndex[i]]) { // there exist greater value at rhs
                swap(digits[i], digits[rightmaxIndex[i]]);
                return stoi(digits);
            }
        }
        return num;
    }
};
// @lc code=end

