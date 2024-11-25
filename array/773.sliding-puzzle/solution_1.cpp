/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // BFS approach, Time: O(), Space: O()
        // Possible move direction of each index
        vector<vector<int>> direction = {{1, 3}, {0, 2, 4}, {1, 5},
                                         {0, 4}, {1, 3, 5}, {2, 4}};
        string start = "", target = "123450";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        int steps = 0;
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int depthSize = q.size();
            while (depthSize-- > 0) {
                string current = q.front();
                q.pop();
                if (current == target) {return steps;}
                int zeroIndex = current.find('0');
                for (int swapIndex : direction[zeroIndex]) {
                    string next = current; // child board to push into the queue
                    swap(next[zeroIndex], next[swapIndex]);
                    if (visited[next] == true) {continue;} // the board is visited
                    visited[next] = true;
                    q.push(next);
                }
            }
            steps++;
        }
        return -1;
    }
};
// @lc code=end

