/*
 * @lc app=leetcode id=147 lang=c
 *
 * [147] Insertion Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *curr = head; // tail of sorted part
    dummy->next = head;

    while (curr) {
        if (curr->next && curr->next->val < curr->val) { // sorting required
            struct ListNode *it = dummy; // iterator to find where to insert the node
            while (it->next && it->next->val < curr->next->val) {
                it = it->next;
            }
            // Adjust the link relations
            struct ListNode *tmp = it->next;
            it->next = curr->next;
            curr->next = curr->next->next; // tail
            it->next->next = tmp;
        } else { // if insertion happen curr still the tail of sorted part -> no need to step
            curr = curr->next;
        }
    }

    return dummy->next;
}
// @lc code=end

