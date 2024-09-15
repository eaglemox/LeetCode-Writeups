/*
 * @lc app=leetcode id=103 lang=c
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = malloc(2000 * sizeof(int));
    int **result = malloc(2000 * sizeof(int *)); // max 2000 * 1 nodes
    if (!root) {return result;}
    // work as a queue
    int front = 0, rear = -1;
    struct TreeNode *queue[2000] = {0};
    
    queue[++rear] = root;
    printf("root %d is enqueued\n", root->val);
    while(queue[front]) {
        result[*returnSize] = malloc((rear - front + 1) * sizeof(int)); // size of this level
        (*returnColumnSizes)[*returnSize] = (rear - front + 1);
        // direction left-right (even) or right-left (odd)
        int idx = ((*returnSize) % 2 == 0) ? 0 : rear - front;
        int step = ((*returnSize) % 2 == 0) ? 1 : -1;
        //                                deque front (front index step forward)
        printf("%d, %d\n", idx, step);
        for (int i = rear; front <= i; front++, idx += step) {
            printf("front: %d, rear: %d\n", front, rear);
            result[*returnSize][idx] = queue[front]->val;
            printf("print %d\n", queue[front]->val);
            if (queue[front]->left) {
                queue[++rear] = queue[front]->left;
                printf("left node %d is enqueued\n", queue[front]->left->val);
            }
            if (queue[front]->right) {
                queue[++rear] = queue[front]->right;
                printf("right node %d is enqueued\n", queue[front]->right->val);
            }
        }
        (*returnSize)++;
    }
    return result;
}
// @lc code=end

