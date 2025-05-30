/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDist(vector<int>& edges, int origNode) { // BFS return the distanc vector from origNode 
        vector<int> dist(edges.size(), -1); // Mark unvisited node -1
        priority_queue<int> q;
        
        dist[origNode] = 0;
        q.push(edges[origNode]);
        
        int i = 1; // Distance from origNode
        while (!q.empty()) {
            int curr = q.top();
            q.pop();
            
            // End of path
            if (curr == -1) {break;}
            
            // Already visited -> not shortest distance
            if (dist[curr] != -1) {continue;}
            
            dist[curr] = i++;
            q.push(edges[curr]);
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = findDist(edges, node1), dist2 = findDist(edges, node2);

        int result = -1, minDist = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            // Either one origNode cannot reach current node
            if (dist1[i] == -1 || dist2[i] == -1) {continue;}
            
            // Max distance required for node1/2 to i-th node
            int commonMax = max(dist1[i], dist2[i]);
            
            if (minDist > commonMax) { // Update new minimal common distance & correspond node index
                minDist = commonMax;
                result = i;
            }
        }

        return result;
    }
};
// @lc code=end

