/*
 * @lc app=leetcode id=2415 lang=c
 *
 * [2415] Reverse Odd Levels of Binary Tree
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
#include <stdlib.h>

void dfs(struct TreeNode* left, struct TreeNode* right, int depth) {
    if (!left || !right) {return;}
    if (depth % 2 == 0) { // at even depth reverse child pair value
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
    }
    dfs(left->left, right->right, depth + 1);
    dfs(left->right, right->left, depth + 1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    // Recursive DFS
    dfs(root->left, root->right, 0);
    return root;
}
// @lc code=end

