/*
 * @lc app=leetcode id=1455 lang=c
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
int isPrefixOfWord(char* sentence, char* searchWord) {
    // Two pointer approach, step once a char if char matches,
    // otherwise skip to the next word or string end
    // Time: O(N), Space: O(1), N: sentence length
    int i = 0, j = 0, index = 1;
    while (sentence[i] != '\0') {
        if (sentence[i] == searchWord[j]) {
            i++;
            j++;
        } else {
            while (sentence[i+1] != '\0' && sentence[i] != ' ') {i++;}
            i++; // step to next char or the null terminator
            index++; // next word
            j = 0; // search from start
        } 
        // Prefix matched
        if (searchWord[j] == '\0') {return index;}
    }
    return -1;
}
// @lc code=end

