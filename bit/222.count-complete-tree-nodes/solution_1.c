/*
 * @lc app=leetcode id=222 lang=c
 *
 * [222] Count Complete Tree Nodes
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
int countNodes(struct TreeNode* root) {
    // My intuitive recursive approach, Time: O(N), Space: O(2N)
    if (!root) {return 0;}
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return 1 + left + right;
}
// @lc code=end

