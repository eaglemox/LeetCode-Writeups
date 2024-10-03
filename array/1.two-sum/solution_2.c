/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#define HASH_SIZE 167

typedef struct Node {
    int idx;
    int val;
    struct Node* next;
} Node;

int hash_fnc(int num) {
    return ((num % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
}

Node* createNode(int idx, int val) {
    Node *newNode = malloc(sizeof(Node));
    newNode->idx = idx;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertHash(Node** obj, int idx, int val) {
    int hash = hash_fnc(val);
    Node *newNode = createNode(idx, val);
    newNode->next = obj[hash];
    obj[hash] = newNode;
}

int searchHash(Node** obj, int idx, int val) {
    int hash = hash_fnc(val);
    Node *currNode = obj[hash];
    while (currNode) {
        // collision may happen -> must check value
        if (currNode->idx != idx && currNode->val == val) {
            return currNode->idx;
        }
        currNode = currNode->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Time: O(N), Space: O(hashSize)
    *returnSize = 2;
    int *result = malloc(*returnSize * sizeof(int));
    Node **hashTable = calloc(HASH_SIZE, sizeof(Node *));

    for (int i = 0; i < numsSize; i++) {
        insertHash(hashTable, i, nums[i]);
    }
    for (int i = 0; i < numsSize; i++) {
        int residual = target - nums[i];
        int residualIdx = searchHash(hashTable, i, residual);
        if (residualIdx != -1 && residualIdx != i) {
            result[0] = i;
            result[1] = residualIdx;
            return result;
        }
    }
    return NULL;
}
// @lc code=end

