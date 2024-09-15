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
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {return result;}
        deque<struct TreeNode*> queue;
        queue.push_back(root);
        int isEven = 1;
        while (!queue.empty()) {
            int nodes = queue.size();
            vector<int> currentLevel;
            for (int i = 0; i < nodes; i++) {
                TreeNode *temp;
                if (isEven) {
                    temp = queue.front();
                    queue.pop_front();
                    currentLevel.push_back(temp->val);
                    // next level FILO (right first)
                    if (temp->left) {queue.push_back(temp->left);}
                    if (temp->right) {queue.push_back(temp->right);}
                } else {
                    temp = queue.back();
                    queue.pop_back();
                    currentLevel.push_back(temp->val);
                    // next level FILO (left first)
                    if (temp->right) {queue.push_front(temp->right);}
                    if (temp->left) {queue.push_front(temp->left);}
                }
            }
            // for (auto& elem : queue) {
            //     cout << elem->val << " ";
            // }cout << endl;
            // toggle left-right direction
            isEven = (isEven) ? 0 : 1;
            result.push_back(currentLevel);
        }
        return result;
    }
};
// @lc code=end
