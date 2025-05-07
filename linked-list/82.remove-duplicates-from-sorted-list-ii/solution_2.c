/*
 * @lc app=leetcode id=82 lang=c
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Removing chunks of nodes with duplicate values
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;
    while (prev && prev->next && prev->next->next) {
        if (prev->next->val == prev->next->next->val) {
            struct ListNode *newnode = prev->next->next;
            while (newnode && newnode->val == prev->next->val) {
                newnode = newnode->next;
            }
            prev->next = newnode;
        } else {
            prev = prev->next;
        }
    }
    return dummy.next;
}
// @lc code=end

