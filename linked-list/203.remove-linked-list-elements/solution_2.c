/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create dummy node point to the head, prevent head deletion
    // Use prev and curr nodes to remove nodes
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *prev = dummy, *curr = head;
    dummy->next = head;
    
    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    return dummy->next;
}
// @lc code=end

