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
    // Directional vector
    int d = 0;
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    // Initialize matrix
    int **matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n; // *returnColumnSizes: a ptr to a int array
        matrix[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }
    int currentX = 0, currentY = 0;
    while (head != NULL) {
        matrix[currentY][currentX] = head->val;
        int nextX = currentX + direction[0], nextY = currentY + direction[1];
        if (nextX >= n || nextY >= m || nextX < 0 || nextY < 0 || matrix[nextY][nextX] != -1) {
            d = (d + 1) % 4;
        }
        currentX += direction[d][0];
        currentY += direction[d][1];
        head = head->next;
    }

    return matrix;
}
// @lc code=end

