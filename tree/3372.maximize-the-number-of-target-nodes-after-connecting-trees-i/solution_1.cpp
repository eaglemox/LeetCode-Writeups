/*
 * @lc app=leetcode id=3372 lang=cpp
 *
 * [3372] Maximize the Number of Target Nodes After Connecting Trees I
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>> &adj, int u, int prev, int k) {
        if (k < 0) return 0;
        int count = 1;
        for (auto &v: adj[u]) {
            if (v != prev) { // prevent circulated visiting
                count += dfs(adj, v, u, k - 1);
            }
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // DFS count max target nodes
        vector<vector<int>> adj1(edges1.size() + 1), adj2(edges2.size() + 1);
        for (auto &e: edges1) { // e: {u, v}, the trees are "un"directional
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e: edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        int maxTarget2 = 0;
        int n = adj1.size(), m = adj2.size();
        vector<int> result(n);
        for (int i = 0; i < m; i++) {
            maxTarget2 = max(maxTarget2, dfs(adj2, i, -1, k - 1)); // tree2 count to depth k-1
        }
        for (int i = 0; i < n; i++) {
            result[i] = dfs(adj1, i, -1, k) + maxTarget2;
        }

        return result;
    }
};
// @lc code=end

