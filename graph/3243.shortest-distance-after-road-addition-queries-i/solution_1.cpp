/*
 * @lc app=leetcode id=3243 lang=cpp
 *
 * [3243] Shortest Distance After Road Addition Queries I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // BFS approach implemented with queue, check the shortest path after each query
        // Time: O(Q*(N+Q)), Space: O(N+Q), N: #nodes, Q: #queries
        vector<int> result;
        vector<vector<int>> adjacent(n, vector<int>(0));
        for (int i = 1; i < n; i++) {
            adjacent[i-1].push_back(i);
        }
        for (auto& query : queries) {
            adjacent[query[0]].push_back(query[1]);
            result.push_back(bfs(n, adjacent));
        }

        return result;
    }

private:
    int bfs(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false); // prevent repeat visit
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int distance = 0;
        while (!q.empty()) { // each node travese exactly once
            int layerNodes = q.size();
            while (layerNodes-- > 0) {
                int currentNode = q.front();
                q.pop();
                if (currentNode == n - 1) {
                    return distance; // first path reach n-1
                }
                for (int neighbor : adj[currentNode]) {
                    if (visited[neighbor]) {continue;}
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            distance++;
        }
        return -1;
    }
};
// @lc code=end

