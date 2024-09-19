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
int binaryOperation(int a, int b, char op) {
    if (op == '+') {return a+b;}
    if (op == '-') {return a-b;}
    if (op == '*') {return a*b;}
    return 0;
}
int isNumber (char* expression) {
    // check if only numbers in expression
    for (int i = 0; i < strlen(expression); i++) {
        if (!isdigit(expression[i])) {return 0;}
    }
    return 1;
}
int* diffWaysToCompute(char* expression, int* returnSize) {
    *returnSize = 0;
    int capacity = 32; // Initial size of return array
    int *result = malloc(capacity * sizeof(int));
    if (isNumber(expression)) {
        result[(*returnSize)++] = atoi(expression);
        return result;
    }
    for (int i = 0; i < strlen(expression); i++) {
        char expr = expression[i];
        if (isdigit(expr)) {continue;}
        char left[MAX_EXP_LEN], right[MAX_EXP_LEN];
        // Left expressions: [0:i-1]
        strncpy(left, expression, i);
        left[i] = '\0';
        // Right expressions: [i+1:strlen(expression) - 1]
        strncpy(right, expression + (i + 1), strlen(expression) - (i + 1));
        right[strlen(expression) - (i + 1)] = '\0';
        int leftSize, rightSize;
        int *leftResult = diffWaysToCompute(left, &leftSize);
        int *rightResult = diffWaysToCompute(right, &rightSize);
        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                // printf("currennt idx: %d\n", *returnSize);
                if (*returnSize >= capacity) {
                    // printf("reallocate array\n");
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int));
                }
                result[(*returnSize)++] = binaryOperation(leftResult[j], rightResult[k], expr);
            }
        }
        free(leftResult);
        free(rightResult);
    }
    return result;
}
// @lc code=end

