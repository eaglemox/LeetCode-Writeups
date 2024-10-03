/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define HASH_SIZE 46703

typedef struct Node {
    int val;
    struct Node* next;
} Node;

int hash_fnc(int num) {
    int hash = 5381;
    hash = ((hash << 5) + hash) + num;
    return ((hash % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
}

bool containsDuplicate(int* nums, int numsSize) {
    // Hash table solution: Time: O(N), Space: O(hashSize)
    Node **hashTable = calloc(HASH_SIZE, sizeof(Node *));

    for (int i = 0; i < numsSize; i++) {
        int hash = hash_fnc(nums[i]);
        Node *node = hashTable[hash];
        while (node) {
            if (node->val == nums[i]) {
                return true;
            }
            node = node->next;
        }
        // node: end of linked-list
        Node* newNode = malloc(sizeof(Node));
        newNode->val = nums[i];
        newNode->next = hashTable[hash];
        hashTable[hash] = newNode;
    }
    return false;
}
// @lc code=end
