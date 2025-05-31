/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> minRolls(n * n + 1, -1); // Minimum dice rolls (turns) to reach certain label
        vector<pair<int,int>> coor(n * n + 1); // Convert label 1~n^2 to (row, col) coordinate
        
        for (int r = n - 1, idx = 1; r >= 0; r--) { // From last to first row
            if ((n - r) & 1) { // Check labeling order (left to right)
                for (int c = 0; c < n; c++) {
                    coor[idx++] = {r, c};
                }
            } else {
                for (int c = n - 1; c >= 0; c--) {
                    coor[idx++] = {r, c};
                }
            }
        }

        queue<int> q;

        q.push(1);
        minRolls[1] = 0; // Starting coordinate

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // All possible next destination after dice rolled
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, col] = coor[next];
                int destination = (board[row][col] != -1) ? board[row][col] : next;

                if (minRolls[destination] != -1) {continue;}

                minRolls[destination] = minRolls[curr] + 1;
                q.push(destination);
            }
        }

        return minRolls[n*n];
    }
};
// @lc code=end

