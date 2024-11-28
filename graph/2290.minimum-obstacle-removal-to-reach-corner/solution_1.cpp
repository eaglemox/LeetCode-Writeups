/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // 0-1 BFS finding distance to the object cell
        // Time: O(M*N), Space: O(M*N), each cells are visited once
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[0][0] = 0;

        deque<pair<int, int>> q;
        q.push_front({0, 0});
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop_front();
            for (auto& dir : direction) {
                int nextRow = row + dir[0], nextCol = col + dir[1];
                // Invalid or visited
                if (nextRow >= m || nextRow < 0 || nextCol >= n || nextCol < 0 || dist[nextRow][nextCol] != -1) {continue;}
                dist[nextRow][nextCol] = dist[row][col] + grid[nextRow][nextCol];
                if (grid[nextRow][nextCol] == 1) {
                    q.push_back({nextRow, nextCol});
                } else {
                    q.push_front({nextRow, nextCol});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
// @lc code=end

