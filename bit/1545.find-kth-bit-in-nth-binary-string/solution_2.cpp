/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        // Find the corresponding bit recursively
        // Time: O(N), Space: O(N)
        if (n == 1) {return '0';}
        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;
        if (k < mid) { // left part
            return findKthBit(n - 1, k);
        } else if (k == mid) {
            return '1';
        } else {
            // find bit 11 at size of 15, is to find the inverse of bit 5 (1-index)
            char correspondingBit = findKthBit(n - 1, len - k + 1);
            return (correspondingBit == '0') ? '1' : '0';
        }
    }
};
// @lc code=end

