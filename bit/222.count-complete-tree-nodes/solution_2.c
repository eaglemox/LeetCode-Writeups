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
    // Complete tree: All nodes are filled except possibly the last level, which is aligned to the left
    // Time: O(logN), Space: O(4N)
    if (!root) {return 0;}
    int depthL = 1, depthR = 1;
    struct TreeNode *leftNode = root, *rightNode = root;
    // if subtree full leftmost depth == rightmost depth -> #node = 2^D - 1
    while (leftNode = leftNode->left) {depthL++;} 
    while (rightNode = rightNode->right) {depthR++;}
    if (depthL == depthR) {return (1 << depthL) - 1;}
    // current subtree is not full (perfect) -> count #node of children subtree recursively
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// @lc code=end

