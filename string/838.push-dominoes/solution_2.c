/*
 * @lc app=leetcode id=838 lang=c
 *
 * [838] Push Dominoes
 */

// @lc code=start
char* pushDominoes(char* dominoes) {
    // Two pointer method
    int left = 0, right = 1;
    while (dominoes[right]) { // p1-> x ... x <-p2
        if (dominoes[right] != '.') {
            if (dominoes[left] == dominoes[right]) { // fill interval
                for (int i = left + 1; i < right; i++) {
                    dominoes[i] = dominoes[left];
                }
            } else if (dominoes[left] == 'R') { // R...L
                int i = left + 1, j = right - 1;
                while (i < j) {
                    dominoes[i++] = 'R';
                    dominoes[j--] = 'L';
                }
            } else if (dominoes[left] == '.' && dominoes[right] == 'L') { // ....L
                for (int i = left; i < right; i++) {
                    dominoes[i] = 'L';
                }
            } // L...R -> skip
            left = right;
            right++;
        } else {right++;}
    }

    if (dominoes[left] == 'R') { // R.... <- tail
        while (dominoes[left]) {
            dominoes[left++] = 'R';
        }
    }
    
    return dominoes;
}
// @lc code=end

