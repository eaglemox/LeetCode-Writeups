/*
 * @lc app=leetcode id=3333 lang=c
 *
 * [3333] Find the Original Typed String II
 */

// @lc code=start
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MOD 1000000007

int possibleStringCount(char* word, int k) {
    // We compute the possible strings of all length and minus possible strings of length k-1
    // The result is the #string of length within [k, len]
    int segmentSize = 0, count = 1;
    int maxLength = strlen(word);
    int segment[maxLength];

    // Initialize array
    memset(segment, 0, sizeof(segment));
    for (int i = 1; i < maxLength; i++) {
        if (word[i] != word[i-1]) {
            segment[segmentSize++] = count;
            count = 1;
        } else {
            count++;
        }
    }
    segment[segmentSize++] = count; // Last segment

    // Compute possible #string of any length, choose 1~segment[i] repeats of a letter for each segment
    long long total = 1;
    for (int i = 0; i < segmentSize; i++) {
        total = (total * segment[i]) % MOD;
    }

    // Shortest length is already >= k -> all possible strings satisfy the condition
    if (segmentSize >= k) {
        return total;
    }

    // Compute possible #string of length < k
    int prevSegment[k+1];
    int currSegment[k+1];
    int prefix[k+1];
    
    // #method first segment can reach length i string
    for (int len = 0; len <= k; len++) {
        prevSegment[len] = (len > 0 && len <= segment[0]) ? 1 : 0; // #method for previous segment to make length i string
        currSegment[len] = 0;
        prefix[len] = 0;
    }

    // Repeat for segment 2 ~ segmentSize
    for (int i = 1; i < segmentSize; i++) {
        prefix[0] = prevSegment[0];
        for (int len = 1; len <= k; len++) {
            prefix[len] = (prefix[len-1] + prevSegment[len]) % MOD;
        }
        
        // Take 1 ~ len-1 letters from previous segment, sum all possible combinations 
        for (int len = 1; len <= k; len++) {
            int minPrevSegmentReq = len - segment[i];
            currSegment[len] = (prefix[len-1] - (minPrevSegmentReq > 0 ? prefix[minPrevSegmentReq-1] : 0) + MOD) % MOD;
        }

        memcpy(prevSegment, currSegment, sizeof(prevSegment));
    }

    long long invalidCount = 0;
    for (int i = 0; i < k; i++) {
        invalidCount = (invalidCount + prevSegment[i]) % MOD;
    }

    return (total - invalidCount + MOD) % MOD;
}
// @lc code=end

