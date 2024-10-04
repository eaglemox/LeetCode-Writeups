/*
 * @lc app=leetcode id=2491 lang=c
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

long long dividePlayers(int* skill, int skillSize) {
    // Sorting Time: O(NlogN), Space: O(1)
    if (skillSize == 2) {return skill[0] * skill[1];}
    qsort(skill, skillSize, sizeof(int), cmp);
    long long target = 0;
    for (int i = 0; i < skillSize; i++) {
        target += skill[i];
    }
    if (target % (skillSize / 2)) {return -1;}
    target /= skillSize / 2;

    long long chemistry = 0;
    for (int i = 0; i < skillSize / 2; i++) {
        if (skill[i] + skill[skillSize-i-1] != target) {
            return -1;
        }
        chemistry += skill[i] * skill[skillSize-i-1];
    }
    return chemistry;
}
// @lc code=end

