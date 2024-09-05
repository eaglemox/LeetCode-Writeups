/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int checkBalance(struct TreeNode* node) {
    if (node == NULL) {return 0;}
    int heightL = 0, heightR = 0;
    if (node->left != NULL) {
        heightL = checkBalance(node->left);
    }
    if (node->right != NULL) {
        heightR = checkBalance(node->right);
    }
    if (heightL == -1 || heightR == -1 || abs(heightL - heightR) > 1) { // unbalanced at subtree
        return -1;
    }
    // printf("node %d, have height: %d & %d\n", node->val, heightL, heightR);
    return (heightL > heightR) ? heightL + 1 : heightR + 1; // if left / right subtree balanced
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {return true;}
    if (checkBalance(root) == -1) {return false;}
    return true;
}
// @lc code=end

