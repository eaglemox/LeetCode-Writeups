/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {return result;}
        int level = 0;
        deque<struct TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int nodes = queue.size();
            vector<int> currentLevel;
            for (int i = 0; i < nodes; i++) {
                TreeNode *temp = queue.front();
                queue.pop_front();
                currentLevel.push_back(temp->val);
                if (temp->left) {queue.push_back(temp->left);}
                if (temp->right) {queue.push_back(temp->right);}
            }
            // for (auto& elem : queue) {
            //     cout << elem->val << " ";
            // }cout << endl;
            if ((level % 2) != 0) {
                reverse(currentLevel.begin(), currentLevel.end());
            }
            level++;
            result.push_back(currentLevel);
        }

        return result;
    }
};
// @lc code=end
