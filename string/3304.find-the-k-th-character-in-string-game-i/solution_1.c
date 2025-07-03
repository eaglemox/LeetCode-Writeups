/*
 * @lc app=leetcode id=3304 lang=c
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start
#define MAX_SIZE 501

char kthCharacter(int k) {
    char word[MAX_SIZE];
    word[0] = 'a';
    
    int len = 1;
    while (len < k) {
        int currentLength = len;
        for (int i = 0; i < currentLength && len < k; i++) {
            word[len++] = (word[i] == 'z') ? 'a' : word[i] + 1;
        }
    }

    return word[k-1];
}
// @lc code=end

