/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */

// @lc code=start
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Max heap approach, Time: O(klogN), Space: O(N)
        int len = nums.size();
        long long score = 0;
        // max heap
        priority_queue<int> pq(nums.begin(), nums.end()); // O(N)
        /* O(NlogN)
        for (int num : nums) {
            pq.push(num);
        }
        */
        // O(klogN)
        while (k > 0) {
            int newVal = pq.top();
            if (newVal == 1) { // ceil(1/3) = 1 -> add 1 for k times
                score += k;
                break;
            } else {
                score += newVal;
            }
            pq.pop();
            pq.push((newVal + 2) / 3); // ceil(val/3)
            k--;
        }
        return score;
    }
};
// @lc code=end

