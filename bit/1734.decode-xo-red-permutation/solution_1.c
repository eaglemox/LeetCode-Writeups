/*
 * @lc app=leetcode id=1734 lang=c
 *
 * [1734] Decode XORed Permutation
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int* returnSize) {
    // Original perm is permutation of [1,N], if n is odd it is guaranteed 
    // find perm[0], or perm[N-1] from XORsum and encoded.
    // encoded[i] = perm[i] ^ perm[i+1] -> perm[i] = perm[i-1] ^ encoded[i-1]
    //    perm[0] = XORsum ^ encoded[1] ^ encoded[3] ^ ... ^ encoded[N-2]
    //  perm[N-1] = XORsum ^ encoded[0] ^ encoded[2] ^ ... ^ encoded[N-3]
    *returnSize = encodedSize + 1;
    int *result = malloc(*returnSize * sizeof(int));

    result[0] = 0;
    for (int i = 1; i <= *returnSize; i++) {result[0] ^= i;}

    for (int i = 1; i < encodedSize; i += 2) {
        result[0] ^= encoded[i];
    }

    for (int i = 1; i < *returnSize; i++) {
        result[i] = result[i-1] ^ encoded[i-1];
    }
    
    return result;
}
// @lc code=end

