/*
 * @lc app=leetcode id=1298 lang=cpp
 *
 * [1298] Maximum Candies You Can Get from Boxes
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // BFS to iterate all boxes we can open
        int n = status.size();
        // Obtained unopen boxes & keys (boxes and keys are unique)
        vector<bool> availableBox(n), availableKey(n);
        
        queue<int> q;
        for (int &box: initialBoxes) {
            if (status[box]) {
                q.push(box);
            } else {
                availableBox[box] = true;
            }
        }

        int result = 0;
        while (!q.empty()) {
            // Open curr box
            int curr = q.front();
            q.pop();

            result += candies[curr];
            
            // Add keys in current box into available keys. If the key to the available box, add it to queue
            for (int &box: keys[curr]) {
                availableKey[box] = true;
                if (availableBox[box]) {
                    availableBox[box] = false;
                    q.push(box);
                }
            }

            // Add boxes in current box into available boxes. 
            // If we already have the key or the box is already open, we can push it immediately.
            for (int &box: containedBoxes[curr]) {
                if (status[box] || availableKey[box]) {
                    q.push(box);
                } else {
                    availableBox[box] = true;
                }
            }

        }

        return result;
    }
};
// @lc code=end

