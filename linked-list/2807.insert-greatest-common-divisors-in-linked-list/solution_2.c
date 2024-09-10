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
    // if (n2 == 0) {return n1;}
    // return gcd(n2, n1 % n2);
    while (n2 != 0) {
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    return n1;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode *current = head;
    while (current->next != NULL) { 
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = gcd(current->val, current->next->val);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }
    return head;
}
// @lc code=end

