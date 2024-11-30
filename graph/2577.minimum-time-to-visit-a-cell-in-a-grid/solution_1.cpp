/*
 * @lc app=leetcode id=2577 lang=cpp
 *
 * [2577] Minimum Time to Visit a Cell In a Grid
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // Similar to [2290] but add a rule that can only visit cell while time >= grid[row][col]
        // Return the min time to reach bottom right cell from the top left cell
        // Use an queue sorted with the minimum visit time to perform BFS
        // Time: O(M*N*log(M*N)), Space: O(M*N), each pq push costs log(M*N) 
        if (grid[1][0] > 1 && grid[0][1] > 1) {return -1;} // impossible to move
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // min heap
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            int time = current[0], row = current[1], col = current[2];
            if (row == m - 1 && col == n - 1) {return time;} // reach bottom right
            if (visited[row][col]) {continue;}
            visited[row][col] = true;
            
            for (vector<int>& dir : direction) {
                int nextRow = row + dir[0], nextCol = col + dir[1];
                // Check index is valid
                if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || visited[nextRow][nextCol]) {continue;}
                // If the time >= grid[row][col], nextTime = time + 1, If the current time havent reach grid[row][col]
                // stepping back & forward can add 2 seconds, if the time difference is odd can access the cell at grid[row][col]
                // while time difference is even the min time to access will become grid[row][col] + 1
                int nextTime = max(grid[nextRow][nextCol] + (((grid[nextRow][nextCol] - time) % 2) == 0), time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        return -1;
    }
};
// @lc code=end

