/*
 * @lc app=leetcode id=2163 lang=cpp
 *
 * [2163] Minimum Difference in Sums After Removal of Elements
 */

// @lc code=start
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        // To minimize the difference (consider negative value) we must let 
        // sum of first n element minimum and sum of next n element maximum.
        // Because n elements will be removed, the boundary of two segment will happen between [n, 2n]
        int m = nums.size(), n = m / 3;
        vector<long long> prefixMin(m), suffixMax(m);
        priority_queue<int> fq;                            // max-heap for finding min n elements for elements 0 ~ i
        priority_queue<int, vector<int>, greater<int>> sq; // min-heap for finding max n elements for elements i ~ m-1
        long long tmp = 0, result = LLONG_MAX; // Large value

        for (int i = 0; i < m; i++) { // L to R
            tmp += nums[i];
            fq.push(nums[i]);
            if (fq.size() > n) { // Keep queueSize <= n 
                tmp -= fq.top();
                fq.pop();
            }
            if (fq.size() == n) {
                prefixMin[i] = tmp;
            }
        }

        tmp = 0;
        for (int i = m - 1; i >= 0; i--) {
            tmp += nums[i];
            sq.push(nums[i]);
            if (sq.size() > n) { // Keep queueSize <= n
                tmp -= sq.top();
                sq.pop();
            }
            if (sq.size() == n) {
                suffixMax[i] = tmp;
            }
        }

        for (int i = n - 1; i < m - n - 1; i++) {
            result = min(result, prefixMin[i] - suffixMax[i+1]);
        }

        return result;
    }
};
// @lc code=end

