/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // We add all possible bitwise OR results of subarrays 
        // ending at the previous element to the result set.
        unordered_set<int> result, curr, prev;
        for (const int num: arr) {
            curr = {num};
            for (const int val: prev) {
                curr.insert(val | num);
            }
            prev = curr;
            result.insert(curr.begin(), curr.end());
        }

        return result.size();
    }
};
// @lc code=end

