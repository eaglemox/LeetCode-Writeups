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
    // Iterate through the list and skip all nodes of value val
    struct ListNode *dummy = malloc(sizeof(struct ListNode)), *curr = dummy;
    dummy->next = head;
    
    while (curr) {
        while (curr->next && curr->next->val == val) {
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
    return dummy->next;
}
// @lc code=end

