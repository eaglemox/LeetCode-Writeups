/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // can only swap once
        // -> swap first digit about to increase and the max digit (last if multiple) after it
        string digits = to_string(num);
        map<int,int> indexMap;
        int len = digits.size();
        for (int i = 0; i < len; i++) {
            indexMap[digits[i]] = i;
        }
        for (int indexL = 0; indexL < len; indexL++) {
            int max = INT_MIN, indexR = indexL;
            for (auto pair : indexMap) {
                if (pair.first > max && pair.second > indexL) { // find max index at rhs of indexL
                    max = pair.first;
                    indexR = pair.second;
                }
            }
            if (max > digits[indexL]) {
                swap(digits[indexL], digits[indexR]);
                return stoi(digits);
            }
        }
        return num;
    }
};
// @lc code=end

