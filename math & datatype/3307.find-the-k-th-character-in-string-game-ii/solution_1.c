/*
 * @lc app=leetcode id=3307 lang=c
 *
 * [3307] Find the K-th Character in String Game II
 */

// @lc code=start
char getCharacter(long long idx, long long length, int operationIdx, int* operations, int operationsSize) {
    // Base case
    if (idx == 0) {return 'a';}
    
    char ret;
    long long halfLength = length >> 1;
    // At later half of the string -> result from first half of the string (word[idx-length/2])
    if (idx >= halfLength) { 
        int steps = 0;
        long long nextLength = length;
        while (nextLength > (idx - halfLength) << 1) {
            steps++;
            nextLength >>= 1;
        }
        ret = getCharacter(idx - halfLength, nextLength, operationIdx - steps, operations, operationsSize);
        if (operations[operationIdx] == 1) { // Shift previous character to get the result
            ret = (ret == 'z') ? 'a' : ret + 1;
        }
    }
    return ret;
}

char kthCharacter(long long k, int* operations, int operationsSize) {
    // We can either append a copy or append a character shifted string to end of the string
    // Note that the k is so large that it's impossible to simulate the operations
    // We can predict k-th character appear after which operation using string length
    // word[k] = oper(word[k-halfLength]) = oper(oper(... oper(word[0])))
    int kOperations = 0;
    long long kLength = 1;
    while (kLength < k) {
        kLength <<= 1;
        kOperations++;
    }
    // Convert k-th char and its correspond operation into 0-index format
    return getCharacter(k - 1, kLength, kOperations - 1, operations, operationsSize);
}
// @lc code=end

