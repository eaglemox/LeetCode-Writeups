/*
 * @lc app=leetcode id=1371 lang=c
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
int findTheLongestSubstring(char* s) {
    // I cannot come up with these character-bit conversion
    int map[26] = {0};
    map['a'-'a'] = 1;  // 00001
    map['e'-'a'] = 2;  // 00010
    map['i'-'a'] = 4;  // 00100
    map['o'-'a'] = 8;  // 01000
    map['u'-'a'] = 16; // 10000
    int mask[32];
    int prefix = 0, length = 0;

    for (int i = 0; i < 32; i++) {mask[i] = -1;}
    for (int i = 0; s[i] != '\0'; i++) {
        prefix ^= map[s[i] - 'a'];
        // mark the index of vowels' appearances 
        if (prefix != 0 && mask[prefix] == -1) {
            mask[prefix] = i;
        }
        length = (length > (i - mask[prefix])) ? length : (i - mask[prefix]);
    }
    return length;
}
// @lc code=end

