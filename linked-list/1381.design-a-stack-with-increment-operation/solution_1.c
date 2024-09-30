/*
 * @lc app=leetcode id=1381 lang=c
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
    int capacity;
} CustomStack;

void printStack(CustomStack* obj) {
    Node *currNode = obj->top;
    printf("size: %d, capacity: %d\n", obj->size, obj->capacity);
    printf("Stack: [");
    while (currNode) {
        printf("%d", currNode->val);
        if (currNode->next) {printf(" ");}
        currNode = currNode->next;
    }
    printf("]\n");
}

CustomStack* customStackCreate(int maxSize) {
    CustomStack *stack = calloc(1, sizeof(CustomStack));
    stack->capacity = maxSize;
    return stack;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->size >= obj->capacity) {return;}
    Node *newNode = malloc(sizeof(Node));
    newNode->val = x;
    // pushed to the top
    obj->size++;
    newNode->next = obj->top;
    obj->top = newNode;
    // printStack(obj);
}

int customStackPop(CustomStack* obj) {
    if (!obj->top) {return -1;}
    obj->size--;
    // Reassign top
    Node *temp = obj->top;
    obj->top = temp->next;
    // Release node
    int popVal = temp->val;
    temp->next = NULL;
    free(temp);
    // printStack(obj);
    return popVal;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    Node *currNode = obj->top;
    // move to bottom k-th node
    int step = obj->size - k;
    while (step > 0) {
        currNode = currNode->next;
        step--;
    }
    while (k > 0 && currNode) {
        currNode->val += val;
        currNode = currNode->next;
        k--;
    }
    // printStack(obj);
}

void customStackFree(CustomStack* obj) {
    Node *currNode = obj->top, *prevNode = NULL;
    while (currNode) {
        prevNode = currNode;
        currNode = currNode->next;
        free(prevNode);
    }
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/
// @lc code=end

