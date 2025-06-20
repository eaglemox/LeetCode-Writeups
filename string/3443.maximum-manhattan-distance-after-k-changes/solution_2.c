/*
 * @lc app=leetcode id=3443 lang=c
 *
 * [3443] Maximum Manhattan Distance After K Changes
 */

// @lc code=start
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))

int maxDistance(char* s, int k) {
    // We can change at most k movements to achieve maximum distance
    // First count the number of N/S, E/W then find direction with lower count of each direction pair
    // Swapping direction to opposite direction can increase manhattan distance by 2
    // e.g. "NSWWEW" -> {N:1,S:1,E:1,W:3} k = 3, original distance is 2 (-2, 0)
    // After swapped 1 'S' and 1 'E' it became {N:2,S:0,E:0,W:4}, maximal distance is 6 (-4, 2)
    int result = 0, count[4] = {0}; // {0,1,2,3}: {N,S,E,W}
    
    char c;
    int i = 0;
    while ((c = *s++) && c != '\0') {
        if (c == 'N') count[0]++;
        else if (c == 'S') count[1]++;
        else if (c == 'E') count[2]++;
        else if (c == 'W') count[3]++;

        i++;
        // Skip movements that cannot make maximum
        if (i + 1 < k) {continue;}

        int currentMax = abs(count[0] - count[1]) + abs(count[2] - count[3]), remainK = k;
        int minY = min(count[0], count[1]), minX = min(count[2], count[3]);

        // Try to swap N/S directions and track the remain changes
        currentMax += 2 * min(k, minY);
        remainK -= min(k, minY);

        // Then swap E/W directions
        currentMax += 2 * min(remainK, minX);

        result = max(result, currentMax);
    }

    return result;
}
// @lc code=end

