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
    struct ListNode *current = head, *prev = NULL;
    int curValue = 0x3f3f3f3f;
    while (current) {
        struct ListNode *tmp = current;
        while (tmp->next && tmp->next->val == current->val) {
            tmp = tmp->next;
        }
        if (current != tmp) {
            if (prev) {
                prev->next = tmp->next;
            } else { // duplicate at head
                head = tmp->next;
            }
            current = tmp->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}
// @lc code=end

