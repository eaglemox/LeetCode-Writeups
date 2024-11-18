/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>
#define HASH_SIZE 29 // Arbitrary prime number

typedef struct Node {
    int val;
    int freq;
    struct Node *next;
} Node;

int majorityElement(int* nums, int numsSize) {
    // Count frequency for all num
    // Map approahc implemented with hashmap
    // Time: O(Nk), Space: O(N), k: maximum list length
    int maxElement, maxCount = 0;
    Node **hashMap = malloc(HASH_SIZE * sizeof(Node *));
    for (int i = 0; i < HASH_SIZE; i++) {hashMap[i] = NULL;}
    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i] % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        Node *list = hashMap[index];
        if (!list) {
            Node *newNode = malloc(sizeof(Node));
            newNode->val = nums[i];
            newNode->freq = 1;
            newNode->next = NULL;
            if (newNode->freq > maxCount) {
                maxCount = newNode->freq;
                maxElement = newNode->val;
            }
            hashMap[index] = newNode;
        } else {
            Node *prev = list;
            bool inserted = false;
            while (list) {
                if (list->val == nums[i]) {
                    list->freq++;
                    if (list->freq > maxCount) {
                        maxElement = list->val;
                        maxCount = list->freq;
                    }
                    inserted = true;
                    break;
                }
                prev = list;
                list = list->next;
            }
            if (!inserted) {
                Node *newNode = malloc(sizeof(Node));
                newNode->val = nums[i];
                newNode->freq = 1;
                newNode->next = NULL;
                prev->next = newNode;
            }
        }
    }
    // It is guaranteed maxElement has majority of counts
    return maxElement;
}
// @lc code=end

