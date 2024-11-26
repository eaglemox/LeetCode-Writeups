/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // The edge (u, v) represent u > v, then the champion is the node with no edges pointed to
        // Time: O(M+N), Space: O(N), M: #edges, N: #nodes
        vector<int> inDegree(n, 0);
        for (const vector<int>& edge : edges) {
            inDegree[edge[1]]++;
        }
        auto it = find(inDegree.begin(), inDegree.end(), 0);

        return find(it + 1, inDegree.end(), 0) != inDegree.end() ? -1 : distance(inDegree.begin(), it);
    }
};
// @lc code=end

