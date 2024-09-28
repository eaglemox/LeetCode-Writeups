/*
 * @lc app=leetcode id=641 lang=c
 *
 * [641] Design Circular Deque
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;


Node* nodeCreate(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->val = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    Node *head;
    Node *tail;
    int size;
    int capacity;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *newDeque = malloc(sizeof(MyCircularDeque));
    newDeque->head = NULL;
    newDeque->tail = NULL;
    newDeque->size = 0;
    newDeque->capacity = k;
    return newDeque;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    // Deque full
    if (obj->size == obj->capacity) {return false;}
    // Link new node
    if (!obj->head) { // first node
        obj->head = nodeCreate(value);
        obj->tail = obj->head;
        obj->size++;
    } else {
        Node *currHead = obj->head;
        currHead->prev = nodeCreate(value);
        obj->head = currHead->prev;
        obj->head->next = currHead;
        obj->size++;
    }
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    // Deque full
    if (obj->size == obj->capacity) {return false;}
    // Link new node
    if (!obj->tail) { // first node
        obj->tail = nodeCreate(value);
        obj->head = obj->tail;
        obj->size++;
    } else {
        Node *currTail = obj->tail;
        currTail->next = nodeCreate(value);
        obj->tail = currTail->next;
        obj->tail->prev = currTail;
        obj->size++;
    }
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    // Deque empty
    if (!obj->head && !obj->tail) {return false;}
    Node *currHead = obj->head;
    if (currHead->next) { // more than one node
        currHead = currHead->next;
        currHead->prev = NULL;
        free(obj->head);
        obj->head = currHead;
        obj->size--;
    } else {
        free(currHead);
        obj->head = obj->tail = NULL;
        obj->size--;
    }
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    // Deque empty
    if (!obj->head && !obj->tail) {return false;}
    Node *currTail = obj->tail;
    if (currTail->prev) {
        currTail = currTail->prev;
        currTail->next = NULL;
        free(obj->tail);
        obj->tail = currTail;
        obj->size--;
    } else {
        free(currTail);
        obj->head = obj->tail = NULL;
        obj->size--;
    }
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (!obj->head) {return -1;}
    return obj->head->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (!obj->tail) {return -1;}
    return obj->tail->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->size == 0);
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->size == obj->capacity);
}

void myCircularDequeFree(MyCircularDeque* obj) {
    Node *currNode = obj->head;
    while (currNode) {
        Node *temp = currNode;
        currNode = currNode->next;
        free(temp);
    }
    obj->head = obj->tail = NULL;
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
// @lc code=end

