/*
 * @lc app=leetcode id=2097 lang=cpp
 *
 * [2097] Valid Arrangement of Pairs
 */

// @lc code=start 
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // We can create a directed graph using numbers as nodes, pairs as edges
        // start node have outDegree = inDegree+1, end node have inDegree = outDegree+1, other nodes have same in/outDegree
        // Time: O(V+E), Space: O(V+E)
        unordered_map<int,deque<int>> adjacent;
        unordered_map<int,int[2]> degree; // {inDegree, outDegree}
        for (auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacent[start].push_back(end);
            degree[start][1]++;
            degree[end][0]++;
        }

        // The pairs (edges) can form a loop that no node have +1 outDegree
        int startNode = pairs[0][0];
        for (auto& deg : degree) {
            if ((deg.second[0] - deg.second[1]) == -1) {
                startNode = deg.first;
                break;
            }
        }

        vector<vector<int>> result;
        dfs(adjacent, result, startNode);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(unordered_map<int,deque<int>>& adj, vector<vector<int>>& result, int node) {
        while (!adj[node].empty()) {
            int nextNode = adj[node].front();
            adj[node].pop_front();
            dfs(adj, result, nextNode);
            result.push_back({node, nextNode});
        }
    }
};
// @lc code=end

