/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
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
    // The list is sorted in ascending order, the next node is duplicated
    // if the value less and equal to current node.
    struct ListNode *current = head;
    while (current && current->next) {
        struct ListNode *next = current->next;
        if (current->val == next->val) {
            current->next = next->next;
            next->next = NULL;
            free(next);
        } else { // no duplicates -> check next node
            current = current->next;
        }
    }
    return head;
}
// @lc code=end

