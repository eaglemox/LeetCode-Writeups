/*
 * @lc app=leetcode id=1367 lang=c
 *
 * [1367] Linked List in Binary Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdbool.h>
bool dfs(struct ListNode* head, struct TreeNode* root) {
    if (head == NULL) {return true;}
    if (root == NULL) {return false;}
    if (head->val == root->val) {
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    // if not head, no dfs required
    return false;
}
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    // just a concise version of "solution_1.c"
    if (head == NULL) {return true;} // found all nodes in list
    if (root == NULL) {return false;}
    // find head
    if (dfs(head, root)) {return true;}
    // to branch
    return isSubPath(head, root->left) || isSubPath(head, root->right); 
}
// @lc code=end

