/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
char* toHex(int num) {
    // Insert hex front head    
    // Time: O(1), Space: O(1)
    if (num == 0) {return "0";}
    char *hexChars = "0123456789abcdef";
    char *result = malloc(9 * sizeof(char));
    result[8] = '\0'; // terminator
    
    // convert into bit representation (two's complement)
    unsigned int n = (unsigned int)num;
    
    int index = 7;
    while (n > 0) {
        result[index--] = hexChars[n & 0xf];
        n >>= 4;
    }
    return result + index + 1;
}
// @lc code=end

