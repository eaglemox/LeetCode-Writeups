/*
 * @lc app=leetcode id=226 lang=c
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    // Recursive approach, swap left and right child
    // Time: O(logN), Space: O(1), N: depth of tree
    if (!root) {return root;}
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
// @lc code=end

