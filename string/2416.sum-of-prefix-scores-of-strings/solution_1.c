/*
 * @lc app=leetcode id=2416 lang=c
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#define LETTER_NUM 26

typedef struct TrieNode {
    struct TrieNode *next[LETTER_NUM];
    int count;
} TrieNode; // alias of "struct TrieNode"

TrieNode* Node_create(void) {
    return calloc(1, sizeof(TrieNode));
}

void Node_insert(TrieNode* rootNode, char* word) {
    TrieNode *currNode = rootNode;
    for (int i = 0; word[i]; i++) {
        int char_idx = word[i] - 'a'; // only lowercase letter
        if (currNode->next[char_idx] == NULL) {
            currNode->next[char_idx] = Node_create();
        }
        currNode = currNode->next[char_idx];
        currNode->count++;
    }
}

int score_search(TrieNode* rootNode, char* word) {
    TrieNode *currNode = rootNode;
    int score = 0;
    for (int i = 0; word[i]; i++) {
        int char_idx = word[i] - 'a';
        if (currNode->next[char_idx] != NULL) {
            currNode = currNode->next[char_idx];
            score += currNode->count;
        }
    }
    return score;
}

void Trie_free(TrieNode* rootNode) {
    if (!rootNode) {return;}
    for (int i = 0; i < LETTER_NUM; i++) {
        Trie_free(rootNode->next[i]);
    }
    
    free(rootNode);
}

int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    *returnSize = wordsSize;
    TrieNode *root = Node_create();
    for (int i = 0; i < wordsSize; i++) {
        Node_insert(root, words[i]);
    }
    int *result = malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        result[i] = score_search(root, words[i]);
    }
    Trie_free(root);
    
    return result;
}
// @lc code=end

