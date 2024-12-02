/*
 * @lc app=leetcode id=1455 lang=c
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
#include <string.h>

int isPrefixOfWord(char* sentence, char* searchWord) {
    // Parse the string then match each prefix
    // Time: O(N), Space: O(L)=(1), N: sentence length, L: word length in sentence
    int index = 1;
    char *word;
    word = strtok(sentence, " ");
    while (word) {
        int i;
        for (i = 0; searchWord[i] != '\0'; i++) {
            if (word[i] != searchWord[i]) {break;}
        }
        if (searchWord[i] == '\0') {return index;}
        word = strtok(NULL, " ");
        index++;
    }
    return -1;
}
// @lc code=end

