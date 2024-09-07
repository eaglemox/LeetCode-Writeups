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
    bool l, r;
    if (head->val == root->val) {
        l = dfs(head->next, root->left);
        r = dfs(head->next, root->right);
        return l || r;
    }
    // if not head, no dfs required
    return false;
}
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    /* 
     * 1. find tree node where value equals to head
     * 2. perform dfs at the node, determining if a subpath exist below the node. 
     * 3. return if any subpath exist.(every tree node checked)
     */
    if (head == NULL) {return true;} // found all nodes in list
    if (root == NULL) {return false;}
    bool l, r, sub = false;
    // find head
    if (head->val == root->val) {
        sub = dfs(head, root);
    }
    // to branch
    l = isSubPath(head, root->left);
    r = isSubPath(head, root->right);
    return sub || l || r; 
}
// @lc code=end

