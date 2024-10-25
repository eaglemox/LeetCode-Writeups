/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort in lexical order, then ignore subfolders
        // Time: O(N*LlogN), Space: O(N*L) 
        sort(folder.begin(), folder.end());

        vector<string> result;
        result.push_back(folder[0]);
        // 1. different parent folder 2. subfolder of last folder
        for (int i = 1; i < folder.size(); i++) {
            string lastfolder = result.back();
            lastfolder += '/';
            if (folder[i].substr(0, lastfolder.size()) != lastfolder) { // different parent folder
                result.push_back(folder[i]);
            }
        }
        return result;
    }
};
// @lc code=end

