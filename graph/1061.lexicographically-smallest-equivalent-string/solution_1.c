/*
 * @lc app=leetcode id=1061 lang=c
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>

int parent[26];

int find(int x) {
    // Find the lexicographically smallest equivalent
    return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
}

void unite(int a, int b) {
    // Add a, b to the set
    int parentA = find(a), parentB = find(b);
    if (parentA == parentB) {return;}
    if (parentA < parentB) {
        parent[parentB] = parentA;
    } else {
        parent[parentA] = parentB;
    }
}

char* smallestEquivalentString(char* s1, char* s2, char* baseStr) {
    int n = strlen(s1), m = strlen(baseStr);
    for (int i = 0; i < 26; i++) {parent[i] = i;}

    for (int i = 0; i < n; i++) {
        unite(s1[i] - 'a', s2[i] - 'a');
    }

    char *result = malloc((m + 1) * sizeof(char));
    for (int i = 0; i < m; i++) {
        int baseIdx = baseStr[i] - 'a';
        result[i] = 'a' + find(baseIdx);
    }
    result[m] = '\0';

    return result;
}

// @lc code=end

