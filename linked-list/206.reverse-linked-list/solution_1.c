/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
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

struct ListNode* reverseList(struct ListNode* head) {
    // Using temp nodes to reverse the link
    // Time: O(N), Space: O(1)
    struct ListNode *prev = NULL, *current = head;
    while (current) {
        struct ListNode *temp = current;
        current = current->next;
        temp->next = prev;
        prev = temp;
    }

    return prev;
}
// @lc code=end

