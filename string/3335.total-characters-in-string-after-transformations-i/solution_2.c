/*
 * @lc app=leetcode id=3335 lang=c
 *
 * [3335] Total Characters in String After Transformations I
 */

// @lc code=start
#define MOD 1000000007

int lengthAfterTransformations(char* s, int t) {
    int count[26] = {0}, length = 0;
    
    while (*s) {
        count[(*s)-'a']++;
        s++;
    }

    for (int i = 0; i < t; i++) {
        int tmp[26];
        memcpy(tmp, count, sizeof(tmp));

        count[0] = tmp[25]; // z -> a
        count[1] = (tmp[0] + tmp[25]) % MOD; // a, z -> b
        for (int j = 1; j < 25; j++) { // from b ~ y -> c ~ z
            count[j+1] = tmp[j];
        }
    }

    for (int i = 0; i < 26; i++) {
        length = (length + count[i]) % MOD;
    }

    return length;
}
// @lc code=end

