/*
 * @lc app=leetcode id=2583 lang=cpp
 *
 * [2583] Kth Largest Sum in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Queue BFS with min heap, Time: O(N*logk), Space: O(k), k: maximum heap size
        // maintain k largest sum, the top of min heap is the k-th largest (min of heap)
        priority_queue<long long, vector<long long>, greater<long long>> levelSum;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long sum = 0;
            int levelSize = q.size();
            for (; levelSize > 0; levelSize--) {
                TreeNode *current = q.front();
                sum += current->val;
                q.pop();
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            levelSum.push(sum);
            if (levelSum.size() > k) {
                levelSum.pop();
            }
        }
        if (levelSum.size() < k) {return -1;}
        return levelSum.top();
    }
};
// @lc code=end