/*
 * @lc app=leetcode id=1371 lang=c
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
#include <stdio.h>
int findTheLongestSubstring(char* s) {
    /* My own spaghetti code
     * Due to we convert lowercase letters into [0, 25] (0b00000 to 0b11001)
     * It's possible XOR operation result in 0b11111 that greater 25 thus the
     * safe way to create the mask is to declare a array with length of 32
     */
    int mask[32];
    int prefix = 0, length = 0;

    for (int i = 0; i < 32; i++) {mask[i] = -1;}
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':   
            case 'u':
                prefix ^= s[i] - 'a';
                printf("prefix XOR of %d: %d\n", i, prefix);
                // mark the index of vowels' appearances 
                if (prefix != 0 && mask[prefix] == -1) {
                    mask[prefix] = i;
                }
                break;
        }
        length = (length > (i - mask[prefix])) ? length : (i - mask[prefix]);
    }
    return length;
}
// @lc code=end

