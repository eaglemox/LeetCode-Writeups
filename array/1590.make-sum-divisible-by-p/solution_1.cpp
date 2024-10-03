/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int numsSize = nums.size(), sum = 0;

        for (int num : nums) {
            sum += num;
            sum %= p;
        }

        int target = sum % p;
        if (target == 0) return 0; // already divisible

        unordered_map<int, int> hashTable;
        hashTable[0] = -1;  // rightSum is the subarray
        int rightSum, len = numsSize;

        for (int i = 0; i < numsSize; ++i) {
            rightSum = (rightSum + nums[i]) % p;

            int leftSum = (rightSum - target + p) % p;

            if (hashTable.find(leftSum) != hashTable.end()) {
                len = min(len, i - hashTable[leftSum]);
            }

            // Store the current remainder and index
            hashTable[rightSum] = i;
        }

        return (len == numsSize) ? -1 : len;
    }
};
// @lc code=end
