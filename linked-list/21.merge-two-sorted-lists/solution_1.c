/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Lists are in non-decreasing order
    if (!list1 && !list2) {return NULL;}
    if (!list1 || !list2) {return ((list1) ? list1: list2);}
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *head = dummy;
    while(list1 || list2) {
        struct ListNode *next;
        if (!list1) {
            next = list2;
            list2 = list2->next;
        } else if (!list2) {
            next = list1;
            list1 = list1->next;
        } else { // list1 && list2
            if (list1->val < list2->val) {
                next = list1;
                list1 = list1->next;
            } else {
                next = list2;
                list2 = list2->next;
            }
        }        
        // step forward
        head->next = next;
        head = head->next;
    }
    head = dummy->next;
    free(dummy);
    return head;
}
// @lc code=end

