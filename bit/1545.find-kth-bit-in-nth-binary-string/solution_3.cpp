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
        // Find the corresponding bit
        // Time: O(N), Space: O(1)
        int len = (1 << n) - 1;
        int invertCount = 0;
        int mid;
        while (k > 1) { // k is concatenated bit
            mid = (len + 1) / 2;
            if (k == mid) {
                return (invertCount % 2) ? '0' : '1'; // center is default '1'
            }
            if (k > mid) {
                k = len - k + 1; // find the mirror of bit k
                invertCount++;
            }
            // find left part
            len /= 2;
        }
        return (invertCount % 2) ? '1' : '0'; // k is corresponding to the first bit '0'
    }
};
// @lc code=end

