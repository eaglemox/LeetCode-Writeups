/*
 * @lc app=leetcode id=725 lang=c
 *
 * [725] Split Linked List in Parts
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode **result = malloc(k * sizeof(struct ListNode*));
    struct ListNode *temp = head;
    *returnSize = k;
    int n = 0;
    while (temp != NULL) { // count list size
        temp = temp->next;
        n++;
    }
    // printf("there are %d node in list to split into %d parts.\n", n, k);
    // all part contain n / k nodes, while first n % k parts have n / k + 1 nodes
    temp = head;
    int splitSize = n / k, unevenSplits = n % k;

    for (int i = 0; i < k; i++) {
        struct ListNode *split = NULL, *tail = NULL;
        int size = splitSize + ((i < unevenSplits) ? 1 : 0);

        for (int j = 0; j < size; j++) {
            if (temp == NULL) {break;}
            // initialize new node
            struct ListNode *newNode = malloc(sizeof(struct ListNode));
            newNode->val = temp->val;
            newNode->next = NULL;

            if (split == NULL) {
                split = newNode;
                tail = split;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            temp = temp->next;
        }
        result[i] = split;
        // printf("split %d: %d\n", i, result[i]);
    }
    return result;
}
// @lc code=end

