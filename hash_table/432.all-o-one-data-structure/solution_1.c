/*
 * @lc app=leetcode id=432 lang=c
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAP_SIZE 50000 // just a random number idk

int inc = 0, dec = 0;
int min = 0, max = 0;

typedef struct keyNode {
    char *key;
    struct keyNode *next;
} keyNode;

keyNode* keyNodeCreate(const char* key) {
    keyNode *newKeyNode = malloc(sizeof(keyNode));
    if (!newKeyNode) {return NULL;}
    
    unsigned int length = strlen(key);
    newKeyNode->key = malloc((length + 1) * sizeof(char));
    if (!newKeyNode->key) {
        free(newKeyNode);
        return NULL;
    }
    
    strncpy(newKeyNode->key, key, length + 1);
    newKeyNode->next = NULL;
    return newKeyNode;
}

void addKeyNode(keyNode* base, const char* key) {
    keyNode *currNode = base;
    while (currNode->next) {
        currNode = currNode->next;
    }
    // currNode is end of LL
    currNode->next = keyNodeCreate(key);
}

bool searchKeyNode(keyNode* base, const char* key) {
    keyNode *currNode = base;
    while (currNode && strcmp(currNode->key, key)) {
        currNode = currNode->next;
    }
    return (currNode != NULL);
}

void deleteKeyNode(keyNode** base, const char* key) {
    printf("finding %s\n", key);
    keyNode *currNode = *base, *prevNode = NULL;
    while (currNode && strcmp(currNode->key, key)) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (!currNode) {
        printf("delete key not found\n");
        return;
    }
    if (!prevNode) {
        *base = currNode->next;
        free(currNode);
    } else {
        prevNode->next = currNode->next;
        free(currNode);
    }
}

// Doubly linked-list
typedef struct Node {
    int count;
    struct Node *prev;
    struct Node *next;
    struct keyNode *keys;
} Node;

Node* nodeCreate(int count) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {return NULL;}
    newNode->count = count;
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->keys = NULL;
    
    return newNode;
}

void nodeRemove(Node* node) {
    Node *prev = node->prev, *next = node->next;
    node->prev = NULL;
    node->next = NULL;
    
    prev->next = next;
    next->prev = prev;
    free(node);
}

unsigned long hash_fn(unsigned char* str) {
    // djb2 hash function
    unsigned long hash = 5381;
    int c;
    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }
    hash %= MAP_SIZE;
    return hash;
}

// Count list
typedef struct {
    Node *head;
    Node *tail;
    Node **hashmap; // maps key to count list ptr
} AllOne;

void printKeys(AllOne* obj) {
    Node *head = obj->head;
    while (head) {
        if (!head->count) {head = head->next;continue;}
        printf("%d: ", head->count);
        if (head->keys) {
            keyNode *currKey = head->keys;
            while (currKey) {
                printf("%s ", currKey->key);
                currKey = currKey->next;
            }
        }
        printf("\n");
        head = head->next;
    }
}

AllOne* allOneCreate() {
    AllOne *countList = malloc(sizeof(AllOne));
    if (!countList) {return NULL;}
    countList->head = nodeCreate(0); // dummy head
    countList->tail = nodeCreate(0); // dummy tail
    countList->head->next = countList->tail; 
    countList->tail->prev = countList->head; 

    countList->hashmap = malloc(MAP_SIZE * sizeof(Node *));
    if (!countList->hashmap) {
        free(countList);
        return NULL;
    }
    for (int i = 0; i < MAP_SIZE; i++) {countList->hashmap[i] = NULL;}
    
    return countList;
}

void allOneInc(AllOne* obj, char* key) {
    inc++;
    int hashVal = hash_fn(key);
    // printf("%s -> %d -> #%d\n", key, hashVal, obj->hashmap[hashVal]);
    if (obj->hashmap[hashVal] && searchKeyNode(obj->hashmap[hashVal]->keys, key)) { // adjust the count of key
        Node *currNode = obj->hashmap[hashVal];
        int count = currNode->count;
        // printf("delete key from k#%d\n", currNode->keys);
        deleteKeyNode(&currNode->keys, key);
        // printf("keys of current node: k#%d\n", currNode->keys);
        Node *nextNode = currNode->next;
        if (nextNode == obj->tail || nextNode->count > (count + 1)) { // add new node
            Node *newNode = nodeCreate(count + 1);
            // printf("create node of count+1: %d\n", newNode);
            newNode->keys = keyNodeCreate(key);
            newNode->prev = currNode;
            newNode->next = nextNode;
            // Re-link neighbor
            currNode->next = newNode;
            nextNode->prev = newNode;
            // Map key to node
            obj->hashmap[hashVal] = newNode;
        } else { // add key to nextNode
            addKeyNode(nextNode->keys, key);
            obj->hashmap[hashVal] = nextNode;
        }
        if (!currNode->keys) {
            // printf("remove empty node #%d, readjust link\n", currNode);
            // prev<-/->curr<-/->new<-->next
            //      v---------^
            nodeRemove(currNode);
        }
    } else { // new key
        Node *first = obj->head->next;
        if (first == obj->tail || first->count > 1) { // first node or no 1-count node
            Node *newNode = nodeCreate(1);
            // printf("create node: #%d\n", newNode);
            newNode->keys = keyNodeCreate(key);
            newNode->prev = obj->head;
            newNode->next = first;
            // Re-link neighbor
            obj->head->next = newNode;
            first->prev = newNode;
            // Map key to node
            obj->hashmap[hashVal] = newNode;
        } else { // add key to 1-count node
            // printf("add to %d\n", first->keys);
            addKeyNode(first->keys, key);
            obj->hashmap[hashVal] = first;
        }
    }
    // printKeys(obj);
}

void allOneDec(AllOne* obj, char* key) {
    dec++;
    int hashVal = hash_fn(key);
    // printf("%s -> %d\n", key, hashVal);
    if (!obj->hashmap[hashVal]) {return;} // no key
    
    Node *currNode = obj->hashmap[hashVal];
    deleteKeyNode(&currNode->keys, key);
    int count = currNode->count;
    
    if (count == 1) { // redirect hashmap to NULL (remove key from DS)
        obj->hashmap[hashVal] = NULL;
    } else {
        Node *prevNode = currNode->prev;
        if (prevNode == obj->head || prevNode->count < (count - 1)) { // add new node
            Node *newNode = nodeCreate(count - 1);
            newNode->keys = keyNodeCreate(key);
            newNode->prev = prevNode;
            newNode->next = currNode;
            // Re-link neighbor
            prevNode->next = newNode;
            currNode->prev = newNode;
            // Map key to node
            obj->hashmap[hashVal] = newNode;
        } else { // add key to previous node
            addKeyNode(prevNode->keys, key);
            obj->hashmap[hashVal] = prevNode;
        }
    }
    if (!currNode->keys) {
        nodeRemove(currNode);
    }
}

char* allOneGetMaxKey(AllOne* obj) {
    max++;
    // printf("tail: %d, prev: %d\n",obj->tail, obj->tail->prev);
    if (obj->tail->prev != obj->head) { // node exist
        // printf("max: %s\n", obj->tail->prev->keys->key);
        return obj->tail->prev->keys->key;
    }
    return "";
}

char* allOneGetMinKey(AllOne* obj) {
    min++;
    // printf("head: %d, next: %d\n",obj->head, obj->head->next);
    if (obj->head->next != obj->tail) { // node exist
        // printf("min: %s\n", obj->head->next->keys->key);
        return obj->head->next->keys->key;
    }
    return "";
}

void allOneFree(AllOne* obj) {
    printf("#Inc: %d #Dec: %d\n#Min: %d #Max: %d\n", inc, dec, min, max);
    inc = dec = min = max = 0;
    Node *temp = obj->head, *prev;
    while (temp) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }
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

