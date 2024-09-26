/*
 * @lc app=leetcode id=729 lang=c
 *
 * [729] My Calendar I
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* Using Binary Search Tree (not balanced) to insert book info 
   Time: O(log(#book)), Space: O(#book)*/

/* struct name "TreeNode" is used by LeetCode */
typedef struct Node {
    int start, end;
    struct Node *left, *right;
} TreeNode;

typedef struct {
    TreeNode *root;
} MyCalendar;

TreeNode* nodeCreate(int start, int end) {
    TreeNode *node = calloc(1, sizeof(TreeNode));
    // Initialization
    node->start = start;
    node->end = end;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void nodeFree(TreeNode* node) {
    if (node) {
        if (node->left) {
            nodeFree(node->left);
        }
        if (node->right) {
            nodeFree(node->right);
        }
        free(node);
    }
}

bool nodeInsert(TreeNode* node, int start, int end) {
    // traverse to leaf, insert new node
    if (end <= node->start) {
        // insert left
        if (!node->left) {
            node->left = nodeCreate(start, end);
            return true;
        } else {
            return nodeInsert(node->left, start, end);
        }
    } else if (start >= node->end) {
        // insert right
        if (!node->right) {
            node->right = nodeCreate(start, end);
            return true;
        } else {
            return nodeInsert(node->right, start, end);
        }
    }
    return false;
}

MyCalendar* myCalendarCreate() {
    MyCalendar *temp = calloc(1, sizeof(MyCalendar));
    return temp;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    // printf("[%d, %d]\n", start, end);
    if (!obj->root) {
        obj->root = nodeCreate(start, end);
        return true;
    }
    bool state = nodeInsert(obj->root, start, end);
    return state;
}

void myCalendarFree(MyCalendar* obj) {
    if (obj) {
        nodeFree(obj->root);
        free(obj);
    }
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/
// @lc code=end

