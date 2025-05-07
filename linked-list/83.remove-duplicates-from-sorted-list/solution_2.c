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
    // Not handling removed nodes
    struct ListNode *current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
        } else { // no duplicates -> check next node
            current = current->next;
        }
    }
    return head;
}
// @lc code=end

