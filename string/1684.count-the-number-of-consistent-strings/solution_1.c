/*
 * @lc app=leetcode id=1684 lang=c
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
// #include <stdio.h>
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int count = wordsSize;
    int alphabet[26] = {0};
    for (int i = 0; i < 26 && allowed[i] != '\0'; i++) {
        // printf("%d, %d\n", allowed[i], allowed[i] - 'a');
        alphabet[allowed[i] - 'a'] = 1;
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!alphabet[words[i][j] - 'a']) {
                count--;
                // printf("word %d contain non-allowed character: %c\n", i, words[i][j]);
                break;
            }
        }
    }
    return count;
}
// @lc code=end

