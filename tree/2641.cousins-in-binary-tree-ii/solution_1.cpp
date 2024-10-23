/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
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
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Two pass BFS approach, Time: O(2N), Space: O(N)
        queue<TreeNode*> q;
        vector<int> levelSums;
        q.push(root);
        while (!q.empty()) {
            int levelSum = 0;
            for (int levelSize = q.size(); levelSize > 0; levelSize--) {
                TreeNode *temp = q.front();
                q.pop();
                levelSum += temp->val;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            levelSums.push_back(levelSum);
        }
        // After first level, the cousinSum = levelSum - siblingSum (include self)
        // Using parent node to compute the cousinSum of children
        // -> next levelSum - parent's childSum
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            for (int levelSize = q.size(); levelSize > 0; levelSize--) {
                TreeNode *temp = q.front();
                q.pop();
                int childSum = 0;
                if (temp->left) {
                    childSum += temp->left->val;
                    q.push(temp->left);
                }
                if (temp->right) {
                    childSum += temp->right->val;
                    q.push(temp->right);
                }
                if (level == 0) {temp->val = 0;} // first level
                if (temp->left) {
                    temp->left->val = levelSums[level+1] - childSum;
                }
                if (temp->right) {
                    temp->right->val = levelSums[level+1] - childSum;
                }
            }
            level++;
        }
        return root;
    }
};
// @lc code=end

