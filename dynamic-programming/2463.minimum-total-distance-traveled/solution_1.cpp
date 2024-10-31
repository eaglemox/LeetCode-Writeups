/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Find the total distance of each factory and its nearest #limit robot
        // Time: O(M*N), Space: O(M*N)
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        // Unpack factory: {pos, limit} -? {pos}*limit
        vector<int> factoryPos;
        for (auto& f : factory) {
            for (int i = 0; i < f[1]; i++) {factoryPos.push_back(f[0]);}
        }
        vector<vector<long long>> memo(robot.size(), vector<long long>(factoryPos.size(), -1));
        return currentMinDistance(0, 0, robot, factoryPos, memo);
    }
private:
    long long currentMinDistance(int robotIndex, int factoryIndex,\
                                 vector<int>& robot, vector<int>&factoryPos, vector<vector<long long>>& memo) {
        if (robotIndex == robot.size()) {return 0;}
        if (factoryIndex == factoryPos.size()) {return 1e12;} // max total distance 2e11
        // retrun recorded distance if visited before
        if (memo[robotIndex][factoryIndex] != -1) {return memo[robotIndex][factoryIndex];}
        
        long long current = abs(robot[robotIndex] - factoryPos[factoryIndex]) + \
                            currentMinDistance(robotIndex + 1, factoryIndex + 1, robot, factoryPos, memo);
        long long skip = currentMinDistance(robotIndex, factoryIndex + 1, robot, factoryPos, memo);
        return memo[robotIndex][factoryIndex] = min(current, skip);
    }
};
// @lc code=end

