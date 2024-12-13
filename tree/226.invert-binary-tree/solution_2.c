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
#define MAX_SIZE 100

struct TreeNode* invertTree(struct TreeNode* root) {
    // Iterative dfs approach
    // Time: O(logN), Space: O(1), N: depth of tree
    if (!root) {return root;}
    int top = -1;
    struct TreeNode *stack[MAX_SIZE]; // array of TreeNode ptrs
    stack[++top] = root;
    while (top >= 0) {
        struct TreeNode *current = stack[top--]; // pop top
        // swap children
        struct TreeNode *temp = current->left;
        current->left = current->right;
        current->right = temp;
        if (current->left) {
            stack[++top] = current->left;
        }
        if (current->right) {
            stack[++top] = current->right;
        }
    }
    return root;
}
// @lc code=end

