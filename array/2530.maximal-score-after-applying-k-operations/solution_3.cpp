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
        // Max heap approach (heapify nums), Time: O(klogN), Space: O(1)
        int len = nums.size();
        long long score = 0;
        // heapify nums into max heap O(N)
        make_heap(nums.begin(), nums.end());
        // O(klogN)
        while (k > 0) {
            int newVal = nums.front();
            if (newVal == 1) { // ceil(1/3) = 1 -> add 1 for k times
                score += k;
                break;
            } else {
                score += newVal;
            }
            // max (head) rotate to last O(2logN)
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            // insert value (back) to corresponding position (heap push)
            nums.push_back((newVal + 2) / 3); // ceil(val/3)
            push_heap(nums.begin(), nums.end()); // O(logN)
            k--;
        }
        return score;
    }
};
// @lc code=end

