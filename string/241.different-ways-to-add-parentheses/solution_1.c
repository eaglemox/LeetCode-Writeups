/*
 * @lc app=leetcode id=241 lang=c
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXP_LEN 21
#define COMB_LEN 2000
int* diffWaysToCompute(char* expression, int* returnSize) {
    *returnSize = 0;
    int length = strlen(expression);
    // printf("length of expression: %d\n", length);
    int *result = malloc(COMB_LEN * sizeof(int));
    if (length == 1 || length == 2) {
        // if consist of operator, valid expression should have length >= 3
        result[(*returnSize)++] = atoi(expression);
        return result;
    }
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {continue;}
        char left[MAX_EXP_LEN], right[MAX_EXP_LEN];
        // Left expressions: [0:i-1]
        strncpy(left, expression, i);
        left[i] = '\0';
        // printf("left: %s\n", left);
        // Right expressions: [i+1:strlen(expression) - 1]
        strncpy(right, expression + (i + 1),\
                (strlen(expression) - 1) - (i + 1) + 1);
        right[(strlen(expression) - 1) - (i + 1) + 1] = '\0';
        // printf("right: %s\n", right);
        // printf("recursive left:\n");
        int leftSize = 0;
        int *leftResult = diffWaysToCompute(left, &leftSize);
        // printf("recursive right:\n");
        int rightSize = 0;
        int *rightResult = diffWaysToCompute(right, &rightSize);
        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                // printf("currennt idx: %d\n", *returnSize);
                switch(expression[i]) {
                    case '+':
                        result[(*returnSize)++] = leftResult[j] + rightResult[k];
                        // printf("%d + %d = %d\n", leftResult[j], rightResult[k], result[(*returnSize)-1]);
                        break;
                    case '-':
                        result[(*returnSize)++] = leftResult[j] - rightResult[k];
                        // printf("%d - %d = %d\n", leftResult[j], rightResult[k], result[(*returnSize)-1]);
                        break;
                    case '*':
                        result[(*returnSize)++] = leftResult[j] * rightResult[k];
                        // printf("%d * %d = %d\n", leftResult[j], rightResult[k], result[(*returnSize)-1]);
                        break;
                }
            }
        }
        free(leftResult);
        free(rightResult);
        // printf("size: %d\n", *returnSize);
    }
    return result;
}
// @lc code=end

