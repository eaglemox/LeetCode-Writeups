/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    int hashTable[100001] = {0};
    for (int i = 0; i < numsSize; i++) { // O(numsSize)
        hashTable[nums[i]] = 1;
    }
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy;
    struct ListNode *node = head;
    while (node != NULL) { // O(N)
        if (hashTable[node->val]) { // in nums
            prev->next = node->next;
            free(node); // free the memory of node point to
            node = prev->next;
        } else { // step next
            prev = node;
            node = node->next;
        }
    }
    // node = dummy;
    // while (node != NULL) {
    //     printf("%d ", node->val);
    //     node = node->next;
    // }
    return dummy->next;
}
// @lc code=end
