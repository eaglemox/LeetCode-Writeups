/*
 * @lc app=leetcode id=432 lang=c
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX_LEN 10
#define TABLE_SIZE 2000
/* This is not a rigorous O(1) solution,
   which requires O(N) sort each Inc() & Dec(),
   N = #nodes                                   */
/* ref: https://leetcode.com/problems/all-oone-data-structure/solutions/3896810/pure-c-hashmap-plus-double-links/ */
typedef struct Node {
    char key[STR_MAX_LEN+1];
    int count;
    struct Node *next;
    struct Node *above;
    struct Node *below;
} Node;


typedef struct {
    Node **hashTable;
    Node *min;
    Node *max;
} AllOne;


AllOne* allOneCreate() {
    AllOne *temp = malloc(sizeof(AllOne));
    temp->hashTable = calloc(TABLE_SIZE, sizeof(Node *));
    temp->min = NULL;
    temp->max = NULL;
    return temp;
}

void printList(AllOne* obj) {
    Node *currNode = obj->min;
    while (currNode) {
        if (currNode->above) {
            printf("%s(%d) <-> ", currNode->key, currNode->count);
        } else {
            printf("%s(%d)", currNode->key, currNode->count);
        }
        currNode = currNode->above;
    }
    printf("\n");
}

unsigned long hash_fn(const char* str) {
    // djb2 hash function
    unsigned long hash = 5381;
    int c;
    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }
    hash %= TABLE_SIZE;
    return hash;
}

void nodeSwap(Node** a, Node** b) {
    // <-->a<-->b<--> to <-->b<-->a<-->
    Node *tempA = *a, *tempB = *b;
    if (tempA->below) {
        tempA->below->above = tempB;
    }
    if (tempB->above) {
        tempB->above->below = tempA;
    }
    tempB->below = tempA->below;
    tempA->above = tempB->above;
    tempB->above = tempA;
    tempA->below = tempB;
    *a = tempB; *b = tempA;
}

void allOneInc(AllOne* obj, char* key) {
    // printf("Inc: %s\n", key);
    int hash = hash_fn(key);
    Node *currNode = obj->hashTable[hash];
    // printf("%s -> %d -> #%d\n", key, hash, currNode);
    while (currNode && strcmp(currNode->key, key)) {
        currNode = currNode->next;
    }
    if (currNode) { // found key
        currNode->count++;
        Node *aboveNode = currNode->above;
        while (aboveNode && currNode->count > aboveNode->count) {
            // swap node
            nodeSwap(&currNode, &aboveNode);
            // printf("swap %s <-> %s\n", currNode->key, aboveNode->key);
            // step
            currNode = aboveNode;
            aboveNode = currNode->above;
            // printf("%s", currNode->key);
            // if (aboveNode) {
            //     printf(" <-> %s\n", aboveNode->key);
            // } else {printf("\n");}
            if (obj->min == currNode) {obj->min = currNode->below;}
        }
        if (!aboveNode) {obj->max = currNode;}
    } else { // add new node (1. no hash, 2. no key in hash)
        Node *newNode = malloc(sizeof(Node));
        strncpy(newNode->key, key, STR_MAX_LEN + 1);
        newNode->count = 1;
        // Insert to hashTable
        newNode->next = currNode;
        obj->hashTable[hash] = newNode;
        // maintain above/below, min/max
        newNode->below = NULL;
        newNode->above = obj->min;
        if (!obj->max) {
            obj->max = newNode;
        }
        if (obj->min) {
            obj->min->below = newNode;
        }
        obj->min = newNode;
    }
    // printList(obj);
    // printf("min: %s, max: %s\n", obj->min->key, obj->max->key);
}

void allOneDec(AllOne* obj, char* key) {
    // printf("Dec: %s\n", key);
    int hash = hash_fn(key);
    Node *prevNode = NULL;
    Node *currNode = obj->hashTable[hash];
    while (currNode && strcmp(currNode->key, key)) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (!currNode) { // shouldn't happen
        printf("Some thing went wrong, decreasing a non-exsiting key!\n");
        return;
    }
    // currNode->count--;
    if ((--currNode->count) == 0) {
        if (!prevNode) { // first node of the LL
            obj->hashTable[hash] = currNode->next;
        } else {
            prevNode->next = currNode->next;
        }
        if (obj->min == currNode) {
            obj->min = currNode->above;
        }
        if (obj->max == currNode) {
            obj->max = currNode->below;
        }
        if (currNode->above) {
            currNode->above->below = currNode->below;
        }
        if (currNode->below) {
            currNode->below->above = currNode->above;
        }
        free(currNode);
    } else {
        Node *belowNode = currNode->below;
        while (belowNode && currNode->count < belowNode->count) {
            nodeSwap(&belowNode, &currNode);
            // printf("swap %s <-> %s\n", belowNode->key, currNode->key);
            currNode = belowNode;
            belowNode = belowNode->below;
            if (obj->max == currNode) {obj->max = currNode->above;}
        }
        if (!belowNode) {
            obj->min = currNode;
        }
    }
    // printList(obj);
}

char* allOneGetMaxKey(AllOne* obj) {
    // printf("get max\n");
    if (!obj->max) {return "";}
    return obj->max->key;
}

char* allOneGetMinKey(AllOne* obj) {
    // printf("get min\n");
    if (!obj->min) {return "";}
    return obj->min->key;
}

void allOneFree(AllOne* obj) {
    free(obj);
}

/**
 * Your AllOne struct will be instantiated and called as such:
 * AllOne* obj = allOneCreate();
 * allOneInc(obj, key);
 
 * allOneDec(obj, key);
 
 * char* param_3 = allOneGetMaxKey(obj);
 
 * char* param_4 = allOneGetMinKey(obj);
 
 * allOneFree(obj);
*/
// @lc code=end

