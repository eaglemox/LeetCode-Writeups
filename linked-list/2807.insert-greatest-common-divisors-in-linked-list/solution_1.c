/*
 * @lc app=leetcode id=2807 lang=c
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
int gcd(int n1, int n2) {
    while (n1 != n2) { // subtraction may cost more time
        if (n1 > n2) {
            n1 -= n2;
        } else {
            n2 -= n1;
        }
    }
    return n1;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode *prev = head;
    struct ListNode *current = prev;
    while (current != NULL) {
        if (prev != current) { // the condiotion is not required
            struct ListNode *newNode = malloc(sizeof(struct ListNode));
            newNode->val = gcd(prev->val, current->val);
            prev->next = newNode;
            newNode->next = current;
        }
        prev = current;
        current = current->next;
    }
    // current = head;
    // while (current != NULL) {
    //     printf("%d ", current->val);
    //     current = current->next;
    // }
    return head;
}
// @lc code=end

