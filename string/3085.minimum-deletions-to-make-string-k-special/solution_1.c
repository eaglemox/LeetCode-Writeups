/*
 * @lc app=leetcode id=3085 lang=c
 *
 * [3085] Minimum Deletions to Make String K-Special
 */

// @lc code=start
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minimumDeletions(char* word, int k) {
    int result = 0x3f3f3f3f;
    int count[26] = {0};

    // Record original frequencies of each letter
    char c;
    while ((c = *word++) && c != '\0') {
        count[c-'a']++;
    }

    // Find #delete required to make string k-special for all base letter (letter of lowest count) a
    for (int i = 0; i < 26; i++) {

        // Skip unoccured letter
        if (count[i] == 0) {continue;}

        int deleted = 0, cntA = count[i];
        for (int j = 0; j < 26; j++) {
            int cntB = count[j];
            if (i == j || cntA == cntB) {continue;}

            if (cntA + k < cntB) {
                deleted += cntB - cntA - k;
            } else if (cntA > cntB) {
                deleted += cntB;
            }
        }

        // Update minimum #deletion found
        result = min(result, deleted);
    }

    return result;
}
// @lc code=end

