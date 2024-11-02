/*
 * @lc app=leetcode id=2490 lang=c
 *
 * [2490] Circular Sentence
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool isCircularSentence(char* sentence) {
    int len = strlen(sentence);
    char head = sentence[0], tail = sentence[len-1];
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) {
            return false;
        }
    }
    return head == tail;
}
// @lc code=end

