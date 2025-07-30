/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Bitwise AND operation only result in a equal or lesser number
        // The answer is the nubmer consecutive equal elements that have maximum value
        int largest = 0, size = 0, result = 0;
        for (const int& num: nums) {
            if (num < largest) { // less
                size = 0;
            } else if (num == largest) {
                size++;
            } else { // current num has maximum value
                largest = num;
                result = size = 1;
            }
            result = max(result, size);
        }
        return result;
    }
};
// @lc code=end

