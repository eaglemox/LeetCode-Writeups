/*
 * @lc app=leetcode id=2326 lang=c
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    // Assign returnSize
    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));
    // Initialize matrix
    int **matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n; // *returnColumnSizes: a ptr to a int array
        matrix[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }
    // Boundary
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    while (head != NULL) {
        for (int col = left; col <= right && head != NULL; col++) { // top: left->right
            matrix[top][col] = head->val;
            head = head->next;
        }
        top++;
        for (int row = top; row <= bottom && head != NULL; row++) { // right: top->bottom
            matrix[row][right] = head->val;
            head = head->next;
        }
        right--;
        for (int col = right; col >= left && head != NULL; col--) { // bottom: right->left
            matrix[bottom][col] = head->val;
            head = head->next;
        }
        bottom--;
        for (int row = bottom; row >= top && head != NULL; row--) { // left: bottom->top
            matrix[row][left] = head->val;
            head = head->next;
        }
        left++;
    }

    return matrix;
}
// @lc code=end

