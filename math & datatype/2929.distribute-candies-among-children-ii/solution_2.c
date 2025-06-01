/*
 * @lc app=leetcode id=2929 lang=c
 *
 * [2929] Distribute Candies Among Children II
 */

// @lc code=start
long long chooseTwo(int x) { // Choose two location to place '|' to seperate three container (child)
    if (x < 0) {return 0;}
    return (long long)x * (x - 1) / 2;
}

long long distributeCandies(int n, int limit) {
    // All combinations, total n + 2 items (candies & children)
    long long result = chooseTwo(n + 2);
    // Atleast one of the children have limit + 1 candies, n + 2 - (limit + 1)
    long long invalid1 = 3 * chooseTwo(n - limit + 1);
    // Atleast two of the children have limit + 1 candies
    long long invalid2 = 3 * chooseTwo(n - 2 * (limit + 1) + 2);
    // All children have more than limit candies
    long long invalid3 = chooseTwo(n - 3 * (limit + 1) + 2);

    return result - invalid1 + invalid2 - invalid3;
}
// @lc code=end

