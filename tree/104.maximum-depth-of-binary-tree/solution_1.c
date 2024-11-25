/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
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
#define max(a, b) ((a > b) ? a : b)

int maxDepth(struct TreeNode* root) {
    // Recursively iterate the nodes to find the max depth
    // Time: O(N), Space: O(H), H: height of tree
    if (!root) {return 0;}
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    // Returning max(maxDepth(root->left), maxDepth(root->right)),
    // causing the max macro repeatly call the maxDepth() result in TLE
    return 1 + max(leftDepth, rightDepth);
}
// @lc code=end

