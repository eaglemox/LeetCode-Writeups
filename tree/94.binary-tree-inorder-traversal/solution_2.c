/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NODE 100
#include <stdio.h>
#include <stdlib.h>
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *list = malloc(MAX_NODE * sizeof(int));
    struct TreeNode *node = root; 
    // interative solution
    // moriss traversal algorithm ref: https://blog.taiwolskit.com/algorithm-morris-traversal
    while (node) {
        if (node->left) {
            // search right most node from left node
            struct TreeNode *temp = node->left;
            while (temp->right && temp->right != node) {
                temp = temp->right;
            }
            // left branch traversed
            if (temp->right) {
                temp->right = NULL; // restore leaf
                list[(*returnSize)++] = node->val;
                node = node->right; // back to parent node
            } else { // rightest is leaf, save link to node
                temp->right = node;
                node = node->left; // move left
            }

        } else { // no left node, list current node and traverse right
            list[(*returnSize)++] = node->val;
            node = node->right;
        }
    }
    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", list[i]);
    }
    return list;
}
// @lc code=end

