/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */

// @lc code=start
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Brute force, Time: O(k*N), Space: O(1) -> TLE when N/k large
        int len = nums.size();
        long long score = 0;
        sort(nums.begin(), nums.end());
        
        // O(k*N)
        while (k > 0) {
            score += nums[len-1];
            int newVal = ceil(nums[len-1] / 3.0);
            if (len > 1) { // pop and insert in ascending order
                nums.pop_back();
                // binary serach smallest nums[i] >= newVal
                auto pos = lower_bound(nums.begin(), nums.end(), newVal); // O(logN)
                // printf("lower bound: %d\n", *pos);
                nums.insert(pos, newVal); // O(N)
            }
            k--;
        }
        return score;
    }
};
// @lc code=end

