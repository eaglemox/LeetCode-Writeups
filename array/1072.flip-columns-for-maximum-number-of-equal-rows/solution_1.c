/*
 * @lc app=leetcode id=1072 lang=c
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 29
#define max(a, b) ((a > b) ? a : b)

typedef struct Node {
    char *pattern; // T&F: element's value compare to start of the row
    int freq;
    struct Node *next;
} Node;

void insertNode(Node** map, char* pattern, int* maxFreq) {
    int hashIndex = 0;
    for (int i = 0; pattern[i] != '\0'; i++) {
        hashIndex += pattern[i];
        hashIndex %= HASH_SIZE;
    }
    Node *root = map[hashIndex];
    if (!root) {
        Node *newNode = malloc(sizeof(Node));
        newNode->pattern = pattern;
        newNode->freq = 1;
        newNode->next = NULL;
        map[hashIndex] = newNode;
    } else {
        Node *prev;
        while (root) {
            if (!strcmp(root->pattern, pattern)) {
                root->freq++;
                *maxFreq = max(*maxFreq, root->freq);
                return;
            }
            prev = root;
            root = root->next;
        }
        Node *newNode = malloc(sizeof(Node));
        newNode->pattern = pattern;
        newNode->freq = 1;
        newNode->next = NULL;
        prev->next = newNode;
    }
    *maxFreq = max(*maxFreq, 1); // only reach when it's new node in map
}

int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
    // Max equal rows will be the number of rows with most common pattern
    // Hashmap approach, counting the pattern frequency
    // Time: O(M*N), Space: O(M*N)
    int maxRows = 0;
    Node **hashMap = malloc(HASH_SIZE * sizeof(Node *));
    for (int i = 0; i < HASH_SIZE; i++) {hashMap[i] = NULL;}
    for (int i = 0; i < matrixSize; i++) {
        char *mask = malloc((matrixColSize[i] + 1) * sizeof(char));
        for (int j = 0; j < matrixColSize[i]; j++) {
            mask[j] = (matrix[i][j] == matrix[i][0]) ? 'T' : 'F';
        }
        mask[matrixColSize[i]] = '\0'; // null terminator
        insertNode(hashMap, mask, &maxRows);
    }
    return maxRows;
}
// @lc code=end

