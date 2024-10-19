/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        // Brute force, Time: O(N*(2^N+1)), Space: O(2^N+1)
        if (k == 0) {return '0';}
        string result = "0";
        for (int i = 1; i < n; i++) {
            string temp = "1";
            for (int j = result.size() - 1; j >= 0; j--) {
                temp += (result[j] == '0') ? '1' : '0';
            }
            result += temp;
        }
        return result[k-1];
    }
};
// @lc code=end

