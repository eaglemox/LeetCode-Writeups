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
    // Recursive approach. Time: O(N), Space: O(N)
    if (!head || !head->next) {return head;}
    // Reach to end of linked list
    struct ListNode *root = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return root;
}
// @lc code=end

