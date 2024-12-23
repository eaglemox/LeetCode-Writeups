/*
 * @lc app=leetcode id=2471 lang=c
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
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
#define MAX_VAL 100000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int minimumOperations(struct TreeNode* root) {
    int front = 0, rear = 0, count = 0;
    int indexMap[MAX_VAL+1] = {-1};
    struct TreeNode *q[MAX_VAL+1];
    q[rear++] = root;
    while (front < rear) { // no empty
        int size = rear - front;
        int nums[size], sortedNums[size];
        for (int i = 0; i < size; i++) {
            struct TreeNode *frontNode = q[front++];
            int value = frontNode->val;
            nums[i] = value;
            sortedNums[i] = value;
            indexMap[value] = i;
            if (frontNode->left) {q[rear++] = frontNode->left;}
            if (frontNode->right) {q[rear++] = frontNode->right;}
        }
        if (front == rear) {
            front = 0;
            rear = 0;
        }
        qsort(sortedNums, size, sizeof(int), cmp);
        // simulate the sorting process
        for (int i = 0; i < size; i++) {
            if (nums[i] == sortedNums[i]) {continue;}
            int targetIndex = indexMap[sortedNums[i]];
            swap(&nums[i], &nums[targetIndex]);
            indexMap[nums[i]] = i;
            indexMap[nums[targetIndex]] = targetIndex;
            count++;
        }
    }
    return count;
}
// @lc code=end

