/*
 * @lc app=leetcode id=3342 lang=cpp
 *
 * [3342] Find Minimum Time to Reach Last Room II
 */

// @lc code=start
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size(), m = moveTime[0].size();
            int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            vector<vector<int>> dis(n, vector<int>(m, 0x3f3f3f3f));
            priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

            dis[0][0] = 0;
            pq.push({0, 0, 0});
            while(!pq.empty()) {
                auto [t, y, x] = pq.top();
                pq.pop();
                for (auto &d : dir) {
                    int newX = x + d[1], newY = y + d[0];
                    if (newY >= 0 && newY < n && newX >= 0 && newX < m) {
                        int minTime = max(t, moveTime[newY][newX]) + (x + y) % 2 + 1;
                        if (minTime < dis[newY][newX]) {
                            dis[newY][newX] = minTime;
                            pq.push({minTime, newY, newX});
                        }
                    }
                }
            }
            
            return dis[n-1][m-1];
        }
    };
// @lc code=end

