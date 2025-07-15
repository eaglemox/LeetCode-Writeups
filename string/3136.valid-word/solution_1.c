/*
 * @lc app=leetcode id=3136 lang=c
 *
 * [3136] Valid Word
 */

// @lc code=start
#include <stdbool.h>

bool isValid(char* word) {
    char c;
    int digit = 0, vowel = 0, consonant = 0;

    while (c = *word) {
        if (c >= '0' && c <= '9') {digit++;}
        else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                 c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {vowel++;}
        else if (c >= 'b' && c <= 'z' || c >= 'B' && c <= 'Z') {consonant++;}
        else {return false;}
        word++;
    }
    
    if (vowel == 0 || consonant == 0 || digit + vowel + consonant < 3) {
        return false;
    }

    return true;
}
// @lc code=end

