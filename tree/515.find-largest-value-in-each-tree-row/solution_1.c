/*
 * @lc app=leetcode id=515 lang=c
 *
 * [515] Find Largest Value in Each Tree Row
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
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)
#define MAX_NODES 10000

int findDepth(struct TreeNode* root) {
    if (!root) {return 0;}
    int leftDepth = findDepth(root->left) + 1;
    int rightDepth = findDepth(root->right) + 1;

    return max(leftDepth, rightDepth);
}

void bfs(struct TreeNode* root, int* largests) {
    if (!root) {return;}
    int front = 0, rear = 0, depth = 0;
    struct TreeNode *q[MAX_NODES];
    q[rear++] = root;

    while (front < rear) {
        int size = rear - front;
        int maxValue = q[front]->val;
        for (int i = 0; i < size; i++) {
            struct TreeNode *frontNode = q[front++];
            maxValue = max(maxValue, frontNode->val);
            if (frontNode->left) {
                q[rear++] = frontNode->left;
            }
            if (frontNode->right) {
                q[rear++] = frontNode->right;
            }
        }
        if (front >= rear) {front = rear = 0;}
        largests[depth++] = maxValue;
    }
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    // BFS iterate nodes in each layer (depth) store the largest value
    // Time: O(N), Space: O(N), N: #nodes, the queue store up to N/2 nodes
    *returnSize = findDepth(root);
    int *result = malloc(*returnSize * sizeof(int));
    bfs(root, result);
    return result;
}
// @lc code=end

