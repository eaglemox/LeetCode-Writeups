/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <string.h>
void itoa(int x, int *arr, int *len) {
    char buffer[12];
    sprintf(buffer, "%d", x);
    *len = strlen(buffer);
    for (int i = 0; i < *len; i++) {
        arr[i] = buffer[i] - '0'; // converting through ascii code
    }
}
bool isPalindrome(int x) {
    int arr[12];
    int len;
    itoa(x, arr, &len);
    // printf("Converted number into array of digits:\n");
    // for (int i = 0; i < len; i++) {
    //     printf("%d ", arr[i]);
    // }printf("\n");
    if (len == 1) {
        // printf("number length is 1, is palindrome.\n");
        return true;
    }
    else {
        // printf("length of number: %d. Checking palindrom...\n", len);
        for (int i = 0; i < (len / 2); i++) {
            // printf("arr[%d]: %d, arr[%d]: %d\n", i, arr[i], len-1-i, arr[len-1-i]);
            if (arr[i] != arr[len-1-i]) {
                return false;
            }           
        }
    }
    return true;
}
// @lc code=end

