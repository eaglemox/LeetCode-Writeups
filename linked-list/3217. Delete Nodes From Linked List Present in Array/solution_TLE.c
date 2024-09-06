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
    // naive solution which can cause TLE on large numsSize
    struct ListNode *node = head;
    struct ListNode *prev = node;
    while (node != NULL) {
        for (int i = 0; i < numsSize; i++) {
            if (node->val == nums[i]) { // found
                printf("node: %d to be removed!\n", node->val);
                if (node == head) {
                    printf("node %d is head, new head is %d\n", node->val, head->next->val);
                    head = head->next;
                } else {
                    prev->next = node->next;
                    if (node->next != NULL) {
                        printf("node %d is removed, prev %d point to %d\n", node->val, prev->val, node->next->val);
                        node->next = NULL;
                        node = prev; // node is removed, move to prev node
                    } else {
                        node->next = NULL;
                        printf("node %d is removed, prev %d point to null\n", node->val, prev->val);
                    }
                }
            }
        }
        prev = node;
        node = node->next;
    }

    node = head;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    return head;
}
// @lc code=end
