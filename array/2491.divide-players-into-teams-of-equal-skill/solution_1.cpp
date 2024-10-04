/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Sort Time: O(NlogN + N + N/2) = O(NlogN), Space: O(1)
        long long target = 0, len = skill.size();
        if (len == 2) {return skill[0] * skill[1];}
        sort(skill.begin(), skill.end());
        for (auto &num : skill) {
            target += num;
        }
        if (target % (len / 2)) {return -1;} // can not be equally teamed
        target /= len / 2;
        long long chmistry = 0;
        for (int i = 0; i < len / 2; i++) {
            if (skill[i] + skill[len-i-1] == target) {
                chmistry += skill[i] * skill[len-i-1];
            } else {return -1;}
        }
        return chmistry;
    }
};
// @lc code=end

