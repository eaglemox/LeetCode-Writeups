/*
 * @lc app=leetcode id=3373 lang=cpp
 *
 * [3373] Maximize the Number of Target Nodes After Connecting Trees II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>> &adj, int u, int prev, vector<bool> &parity, bool even = true) {
        int count = even;
        parity[u] = even;
        for (auto &v: adj[u]) {
            if (v != prev) { // prevent circulated visiting
                count += dfs(adj, v, u, parity, !even);
            }
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // DFS count max target nodes, the problem can be simplified into:
        // Connect even/odd node in tree1 to even/odd node in tree2, count the 
        vector<vector<int>> adj1(edges1.size() + 1), adj2(edges2.size() + 1);
        for (auto &e: edges1) { // e: {u, v}, the trees are "un"directional
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e: edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }


        int n = adj1.size(), m = adj2.size();
        vector<int> result(n);
        vector<bool> parity1(n), parity2(m);
        int even1 = dfs(adj1, 0, -1, parity1), odd1 = n - even1;
        int even2 = dfs(adj2, 0, -1, parity2), odd2 = m - even2;

        for (int i = 0; i < n; i++) {
            // connect to node with maximum count, add to even/odd count of current node in tree1
            result[i] = max(even2, odd2) + (parity1[i] ? even1 : odd1);
        }

        return result;
    }
};
// @lc code=end

