/*
 * @lc app=leetcode id=3043 lang=c
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_LEN 10
#define max(a, b) ((a > b) ? a : b)

/* Each node with node ptr for digit 0~9 (uninitialized)
 * Doesn't have the "val" variable, using if the ptr is null
 * to keep track with the digits in the prefix.             */
typedef struct TrieNode {
    // the index is the digit itself
    struct TrieNode *children[10];
} TrieNode;
/* Return an initialized node */
TrieNode* Node_create(void) {
    return calloc(1, sizeof(TrieNode));
}
/* Free node and children (if exist) */
void Node_free(TrieNode* node) {
    if (node) {
        for (int i = 0; i < 10; i++) {
            Node_free(node->children[i]);
        }
        free(node);
    }
}

/* The struct only contains the root node */
typedef struct Trie {
    TrieNode *node;
} Trie;
/* Return a allocated ptr with initialized node */ 
Trie* Trie_create(void) {
    Trie *temp = malloc(sizeof(Trie));
    if (temp == NULL) {return NULL;}
    temp->node = Node_create();
    if (temp->node == NULL) {return NULL;}
    return temp;
}
/* Insert digit by digit into the trie 
   Using c_str to mitigate the need of length argument*/
void Trie_insert(Trie* root, char* digits) {
    TrieNode *currNode = root->node;
    for (int i = 0; digits[i]; i++) {
        int digit = digits[i] - '0';
        if (currNode->children[digit] == NULL) {
            currNode->children[digit] = Node_create();
        }
        currNode = currNode->children[digit];
    }
}
/* Search digit by digit in the trie, return the common prefix length (tree depth) */
int Trie_find(Trie* root, char* digits) {
    int depth = 0;
    TrieNode *currNode = root->node;
    for (int i = 0; digits[i]; i++) {
        int digit = digits[i] - '0';
        if (currNode->children[digit] == NULL) {
            break;
        } // else found next node
        depth++;
        currNode = currNode->children[digit];
    }
    return depth;
}
/* Free space of the trie */
void Trie_free(Trie* root) {
    Node_free(root->node);
    root->node = NULL;
    
    free(root);
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    // Using Trie
    int length = 0;
    Trie *trie = Trie_create();
    char buffer[10];
    
    // Insert numbers in arr1 into trie
    for (int i = 0; i < arr1Size; i++) {
        sprintf(buffer, "%d", arr1[i]);
        Trie_insert(trie, buffer);
    }

    // Search common prefix length of numbers in arr2
    for (int i = 0; i < arr2Size; i++) {
        sprintf(buffer, "%d", arr2[i]);
        int temp = Trie_find(trie, buffer);
        length = max(length, temp);
    }
    Trie_free(trie);

    return length;
}
// @lc code=end

