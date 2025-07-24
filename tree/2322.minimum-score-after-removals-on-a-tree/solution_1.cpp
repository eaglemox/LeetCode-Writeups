/*
 * @lc app=leetcode id=2322 lang=cpp
 *
 * [2322] Minimum Score After Removals on a Tree
 */

// @lc code=start
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int time = 0;

    void dfs(int node, int parent, vector<int>& nums, vector<vector<int>>& adj, vector<int>& xorSum,
             vector<int>& in, vector<int>& out) {
        in[node] = time++;
        xorSum[node] = nums[node];

        for (auto& child: adj[node]) {
            if (child == parent) {continue;}
            dfs(child, node, nums, adj, xorSum, in, out);
            xorSum[node] ^= xorSum[child];
        }

        out[node] = time;
    }

    int diff(int a, int b, int c) {
        return max(a, max(b, c)) - min(a, min(b, c));
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        vector<int> xorSum(n), in(n), out(n);

        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);1
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, nums, adj, xorSum, in, out);
        
        int result = INT_MAX;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (in[v] > in[u] && in[v] < out[u]) { // u is parent of v
                    result = min(result, diff(xorSum[0] ^ xorSum[u], xorSum[u] ^ xorSum[v], xorSum[v]));
                } else if (in[u] > in[v] && in[u] < out[v]) { // v is parent of u
                    result = min(result, diff(xorSum[0] ^ xorSum[v], xorSum[v] ^ xorSum[u], xorSum[u]));
                } else {
                    result = min(result, diff(xorSum[0] ^ xorSum[u] ^ xorSum[v], xorSum[u], xorSum[v]));
                }
            }
        }

        return result;
    }
};
// @lc code=end

