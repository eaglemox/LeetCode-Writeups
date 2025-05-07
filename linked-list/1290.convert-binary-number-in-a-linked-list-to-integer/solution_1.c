/*
 * @lc app=leetcode id=1290 lang=c
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    // Read the bit value from the head node (MSB)
    // For each iteration left shift the (decimal) number 1 bit 
    // then assign the number's LSB.
    // Time: O(0 <= #nodes <= 30), Space: O(1)
    int result = 0;
    while (head) {
        result <<= 1;
        result |= head->val;
        head = head->next;
    }
    return result;
}
// @lc code=end

