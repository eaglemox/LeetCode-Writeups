/*
 * @lc app=leetcode id=1590 lang=c
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 16787 // prime number to reduce the chance of collision 
#define min(a, b) ((a < b) ? a : b)

typedef struct HashNode {
    int remainder;
    int idx;
    struct HashNode* next;
} HashNode;


int hashFunction(int key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;  // ensure positive
}

HashNode* createNode(int remainder, int idx) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->remainder = remainder;
    newNode->idx = idx;
    newNode->next = NULL;
    return newNode;
}

void insertHash(HashNode** hashTable, int remainder, int idx) {
    int hashIndex = hashFunction(remainder);
    // search if node of remainder exist
    HashNode* node = hashTable[hashIndex];
    while (node != NULL) {
        if (node->remainder == remainder) {
            break;
        }
        node = node->next;
    }
    if (node) { // update node->idx
        node->idx = idx;
    } else { // new node
        HashNode* newNode = createNode(remainder, idx);
        newNode->next = hashTable[hashIndex];  // insert head
        hashTable[hashIndex] = newNode;
    }
}

int searchHash(HashNode** hashTable, int remainder) {
    int hashIndex = hashFunction(remainder);
    HashNode* node = hashTable[hashIndex];
    while (node != NULL) {
        if (node->remainder == remainder) {
            return node->idx;
        }
        node = node->next;
    }
    return -1;  // not found
}

void freeHashTable(HashNode** hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int minSubarray(int* nums, int numsSize, int p) {
    HashNode** hashTable = malloc(HASH_SIZE * sizeof(HashNode));

    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;  // Initialization
    }
    
    unsigned long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        sum %= p;
    }

    int target = sum % p;
    if (target == 0) { // already divisible
        return 0;
    }

    int rightSum = 0, len = numsSize;

    for (int i = 0; i < numsSize; i++) {
        rightSum = (rightSum + nums[i]) % p;
        int leftSum = (rightSum - target + p) % p;  // non-negative module

        int leftIdx = searchHash(hashTable, leftSum);
        if (leftIdx != -1) {
            len = min(len, i - leftIdx);
        } else if (leftSum == 0) { // rightSum is the subarray
            len = min(len, i+1);
        }
        
        // insert to current prefix sum to hashTable
        insertHash(hashTable, rightSum, i);
    }

    freeHashTable(hashTable);

    return (len == numsSize) ? -1 : len;
}
// @lc code=end
