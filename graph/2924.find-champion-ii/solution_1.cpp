/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
#include <vector>
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
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (champion != -1) {return -1;}
                champion = i;
            }
        }
        return champion;
    }
};
// @lc code=end

