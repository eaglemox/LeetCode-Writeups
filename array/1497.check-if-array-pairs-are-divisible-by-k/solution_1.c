/*
 * @lc app=leetcode id=1497 lang=c
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// void printArray(int *arr, int len) {
//     for (int i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//         if (i == len - 1) {printf("\n");}
//     }
// }

bool canArrange(int* arr, int arrSize, int k) {
/* count how many #module of k = M[0:k-1] in the arr
   if M[i] ==  M[k-i], there exist divisible pairs of n*k + i, n*k + k-i 
   and M[0] should be even to be divisible                               */
    int *freq = calloc(k, sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        freq[((arr[i] % k) + k) % k]++;
        // printArray(freq, k);
    }
    // odd multiple of k
    if (freq[0] % 2) {return false;}
    for (int j = 1; j <= k / 2; j++) {
        // handle the center (k/2) freq j == k-j
        if (j == (k / 2.0) && (freq[j] % 2)) {
            return false;
        }
        // (freq + complement freq) pairs
        if (freq[j] != freq[k-j]) {return false;}
    }
    return true;
}
/*
ex.1: 5 % 2 = 1
0,1,2,3,4
2,2,2,2,2
ex.2: 7 % 2 = 1
0,1,2,3,4,5,6
0,1,1,1,1,1,1
ex.3: 10 % 2 = 0
0,1,2,3,4,5,6,7,8,9
0,1,1,1,1,1,1,0,0,0
*/
// @lc code=end

