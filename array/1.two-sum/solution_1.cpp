/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans = {0, 1};
        for(auto num_1 = nums.begin(); num_1 < nums.end(); num_1++){
            for (auto num_2 = num_1 + 1; num_2 < nums.end(); num_2++){
                // cout << *num_1 << " " << *num_2 << ": " << *num_1 + *num_2 << endl;
                if((*num_1 + *num_2) == target){
                    ans = {int(distance(nums.begin(), num_1)), int(distance(nums.begin(), num_2))}; // turn iterator into int index
                }
            }
        }
        return ans;
        // return vector<int> {0, 1};
    }
};
// @lc code=end

