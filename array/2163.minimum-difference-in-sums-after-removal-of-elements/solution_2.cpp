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
        // Reduce redundant computation, memory
        int m = nums.size(), n = m / 3;
        vector<long long> prefixMin(n + 1), suffixMax(n + 1); // May access n-th element
        priority_queue<int> fq;                            // max-heap for finding min n elements for elements 0 ~ i
        priority_queue<int, vector<int>, greater<int>> sq; // min-heap for finding max n elements for elements i ~ m-1
        
        long long tmp = 0, result = LLONG_MAX; // Large value
        for (int i = 0; i < m - n; i++) { // L to R
            tmp += nums[i];
            fq.push(nums[i]);
            if (fq.size() > n) { // Keep queueSize <= n 
                tmp -= fq.top();
                fq.pop();
            }
            // Already n elements, shift i [n-1, 2*n-1] to [0, n]
            if (i >= n - 1) {prefixMin[i-n+1] = tmp;}
        }

        tmp = 0;
        for (int i = m - 1; i >= n; i--) {
            tmp += nums[i];
            sq.push(nums[i]);
            if (sq.size() > n) { // Keep queueSize <= n
                tmp -= sq.top();
                sq.pop();
            }
            // Already n elements, shift i [n, 2n] to [0, n]
            if (i <= m - n) {suffixMax[i-n] = tmp;}
        }

        for (int i = 0; i <= n; i++) {
            result = min(result, prefixMin[i] - suffixMax[i]);
        }

        return result;
    }
};
// @lc code=end

