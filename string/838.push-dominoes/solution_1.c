/*
 * @lc app=leetcode id=838 lang=c
 *
 * [838] Push Dominoes
 */

// @lc code=start
#include <stdbool.h>

bool isFinalState(char* dominoes, int n) {
    // All vertical dominoes won't be pushed by thier adjacent dominoes
    if (n == 1) {return true;}
    for (int i = 0; i < n; i++) {
        if (dominoes[i] != '.') {continue;}
        // Check adjacent dominoes' states of vertical dominoes '.'
        if (i + 1 < n && dominoes[i+1] == 'L' && (i == 0 || dominoes[i-1] != 'R')) {
            return false;
        } else if (i > 0 && dominoes[i-1] == 'R' && (i == n - 1 || dominoes[i+1] != 'L')) {
            return false;
        }
    }

    return true;
}

void nextState(char* dominoes, int n) {
    char *tmp = malloc(sizeof(char) * (n + 1));
    memcpy(tmp, dominoes, (n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (tmp[i] != '.') {continue;}
        if (i + 1 < n && tmp[i+1] == 'L' && (i == 0 || tmp[i-1] != 'R')) {
            dominoes[i] = 'L';
        } else if (i > 0 && tmp[i-1] == 'R' && (i == n - 1 || tmp[i+1] != 'L')) {
            dominoes[i] = 'R';
        }
    }
    free(tmp);
}

char* pushDominoes(char* dominoes) {
    // Already failing domino's state won't be changed by additional force, thus
    // final states of dominoes only depend on initial states of adjacent dominoes
    int n = 0; // number of dominoes
    while (dominoes[n]) {n++;}
    while (!isFinalState(dominoes, n)) {
        nextState(dominoes, n);
    }
    return dominoes;
}
// @lc code=end

