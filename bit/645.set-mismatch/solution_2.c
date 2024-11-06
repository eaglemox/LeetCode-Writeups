/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#define HASH_SIZE 7

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int insertNode(Node **map, int val) {
    int index = val % HASH_SIZE;
    Node *newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    if (!map[index]) { // first node
        map[index] = newNode;
        return 0;
    }
    Node *currNode = map[index];
    while (currNode != NULL) {
        if (currNode->value == val) {return -1;}
        currNode = currNode->next;
    }
    currNode = newNode;
    return 0;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    // Brute force approach, iterate to find duplicate number
    // Difference = completeSum - errorSum = missing - duplicate
    // Time: O(N), Space: O(N)
    *returnSize = 2;  // {duplicate, missing}
    Node **hashMap = malloc(HASH_SIZE * sizeof(Node *));
    for (int i = 0; i < HASH_SIZE; i++) {
        hashMap[i] = NULL;
    }

    int duplicate = -1;
    int diff = (numsSize + 1) * numsSize / 2;
    for (int i = 0; i < numsSize; i++) {
        if (duplicate == -1 && insertNode(hashMap, nums[i]) == -1) {
            duplicate = nums[i];
        }
        diff -= nums[i];
    }

    int *result = malloc(*returnSize * sizeof(int));
    result[0] = duplicate;
    result[1] = diff + result[0];
    return result;
}
// @lc code=end

