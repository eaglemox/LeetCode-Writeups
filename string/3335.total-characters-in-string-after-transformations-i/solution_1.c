/*
 * @lc app=leetcode id=3335 lang=c
 *
 * [3335] Total Characters in String After Transformations I
 */

// @lc code=start
#define MOD 1000000007

int lengthAfterTransformations(char* s, int t) {
    int count[26] = {0}, length = strlen(s);
    
    while (*s) {
        count[(*s)-'a']++;
        s++;
    }
    
    for (int i = 0; i < t; i++) {
        int tmp[26] = {0};
        memcpy(tmp, count, sizeof(tmp));
    
        for (int j = 0; j < 26; j++) {
            if (j == 25 && tmp[j]) { // there are 'z' can be transfromed
                count[1] = (count[1] + tmp[j]) % MOD;
                length = (length + tmp[j]) % MOD;
            }
            count[(j+1)%26] = tmp[j];
        }
    }
    
    return length;
}
// @lc code=end

