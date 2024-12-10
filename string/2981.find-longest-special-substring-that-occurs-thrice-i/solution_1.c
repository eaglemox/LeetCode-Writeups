/*
 * @lc app=leetcode id=2981 lang=c
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define HASH_SIZE 23

typedef struct Node {
    int freq;
    char *str;
    struct Node *next;
} Node;

int hashFunc(char* str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += str[i];
    }
    return hash % HASH_SIZE;
}

int insertNode(Node** root, char* str) {
    Node *head = root[hashFunc(str)], *prev;
    while (head) {
        // count freq and check if the str occured thrice
        if (strcmp(head->str, str) == 0) {
            head->freq++;
            return (head->freq == 3) ? strlen(str) : -1;
        }
        prev = head; // used to insert to tail
        head = head->next;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->freq = 1;
    newNode->str = malloc((strlen(str) + 1) * sizeof(char));
    strncpy(newNode->str, str, strlen(str) + 1);
    newNode->next = NULL;
    if (!head) { // the list is empty
        root[hashFunc(str)] = newNode;
    } else {
        prev->next = newNode;
    }
    return -1;
}

int maximumLength(char* s) {
    // Brute force with custom hashTable
    // Time: O(N^2), Space: O(N)
    Node **hashTable = malloc(HASH_SIZE * sizeof(Node *));
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = malloc(sizeof(Node *));
        hashTable[i] = NULL;
    }
    int len = strlen(s);
    for (int i = len; i > 0; i--) {
        for (int j = 0; j <= len - i; j++) {
            // Check the substring is special (all same letter)
            bool isSpecial = true;
            for (int k = j + 1, prev = s[j]; k < j + i; k++) {
                if (s[k] != prev) {isSpecial = false;}
                prev = s[k];
            }
            if (!isSpecial) {continue;}
            char *substr = malloc((i + 1) * sizeof(char));
            strncpy(substr, s + j, i);
            substr[i] = '\0';
            int temp = insertNode(hashTable, substr);
            // BC. we search from longest length to shortest length, the length of first substring occurs thrice is the answer
            if (temp != -1) {return temp;} 
        }
    }
    return -1;
}
// @lc code=end

