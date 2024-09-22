/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
#include <algorithm>
using namespace std;
class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        k--;

        while (k > 0) {
            int steps = 0;
            for (long long lowerbound = prefix, upperbound = prefix + 1;\
                 lowerbound <= n; lowerbound *= 10, upperbound *= 10) {
                steps += min((n + 1LL), upperbound) - lowerbound;
            }
            if (steps <= k) {
                k -= steps;
                prefix++;
            } else {
                k--;
                prefix *= 10;
            }
        }
        return prefix;
    }
};
// @lc code=end

