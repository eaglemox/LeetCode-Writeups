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
    struct ListNode *prev = head, *curr = head->next;
    dummy->next = head;

    while (curr) {
        if (prev->val > curr->val) { // sorting required
            struct ListNode *tmp = dummy; // where to insert curr node
            while (tmp->next && tmp->next->val < curr->val) {
                tmp = tmp->next;
            }
            prev->next = curr->next;
            curr->next = tmp->next;
            tmp->next = curr;

            curr = prev->next;
        } else { // if insertion happen prev still the tail of sorted part -> no need to step
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy->next;
}// @lc code=end

