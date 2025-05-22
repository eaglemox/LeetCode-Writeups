/*
 * @lc app=leetcode id=3362 lang=cpp
 *
 * [3362] Zero Array Transformation III
 */

// @lc code=start
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> maxHeap; // max heap to store ri of each query with li <= current index
        vector<int> end(nums.size() + 1, 0);
        int sum = 0, j = 0; // max decrement sum and query index j
        for (int i = 0; i < nums.size(); i++) {
            sum -= end[i];
            while (j < queries.size() && queries[j][0] <= i) {
                maxHeap.push(queries[j][1]);
                j++;
            }

            while (sum < nums[i]) { // not enough queries to make zero array
                if (maxHeap.empty() || maxHeap.top() < i) { // no query can help
                    return -1;
                }
                end[maxHeap.top()+1]++;
                maxHeap.pop();
                sum++;
            }
        }

        return maxHeap.size(); // remain queries in the heap is the result (redundant queries)
    }
};
// @lc code=end

