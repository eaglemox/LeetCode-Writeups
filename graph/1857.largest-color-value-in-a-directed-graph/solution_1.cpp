/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dfs(int i, string &colors, vector<vector<int>> &adj, vector<vector<int>> &count, vector<int> &visited) {
        if (!visited[i]) {
            visited[i] = 1; // mark as currently visiting for loop detection
            for (int &v: adj[i]) { // node u -> v
                if (dfs(v, colors, adj, count, visited) == INT_MAX) {
                    return INT_MAX;
                }
                for (int c = 0; c < 26; c++) {
                    count[i][c] = max(count[i][c], count[v][c]);
                }
            }
            count[i][colors[i]-'a']++;
            visited[i] = 2; // mark visited
        }

        return visited[i] == 2 ? count[i][colors[i]-'a'] : INT_MAX; // return cached value or loop occured
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int nodes = colors.size(), result = 0;
        vector<vector<int>> adj(nodes), count(nodes, vector<int>(26)); // count[u][c]: the count of color c nodes for path to node u
        vector<int> visited(nodes);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        for (int i = 0; i < nodes && result != INT_MAX; i++) {
            result = max(result, dfs(i, colors, adj, count, visited)); // update result
        }

        return result == INT_MAX ? -1 : result;
    }
};
// @lc code=end

