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
void traversal(struct TreeNode* node, int* list, int* returnSize) {
    if (node == NULL) {return;}
    // left
    traversal(node->left, list, returnSize);
    // parent
    list[(*returnSize)++] = node->val;
    // right
    traversal(node->right, list, returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *list = malloc(MAX_NODE * sizeof(int));

    traversal(root, list, returnSize);

    // for (int i = 0; i < *returnSize; i++) {
    //     printf("%d ", list[i]);
    // }
    return list;
}
// @lc code=end

