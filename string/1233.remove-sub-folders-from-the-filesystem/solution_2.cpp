/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Store folder paths in trie
        // Time: O(N*L), Space: O(N*L) but iss and hashtable overhead is large
        vector<string> result;
        root = new TrieNode;
        for (string p : folder) {
            TrieNode *currNode = root;
            istringstream iss(p);
            string folder;
            while (getline(iss, folder, '/')) {
                // first '/' will parse empty string, "/a" -> {"", "a"}
                if (folder.empty()) {continue;}
                // insert new folder path
                if (currNode->leaves.find(folder) == currNode->leaves.end()) {
                    currNode->leaves[folder] = new TrieNode;
                }
                currNode = currNode->leaves[folder];
            }
            currNode->isPathEnd = true;
        }
        for (string p : folder) {
            TrieNode *currNode = root;
            istringstream iss(p);
            string folder;
            bool isSubfolder = false;
            while (getline(iss, folder, '/')) {
                if (folder.empty()) {continue;}
                currNode = currNode->leaves[folder];
                // is end of a folder but not current folder's end -> current folder is subfolder
                if (currNode->isPathEnd && !iss.eof()) {
                    isSubfolder = true;
                    break;
                }
            }
            if (isSubfolder) {
                result.push_back(p);
            }
        }
        return result;
    }
private:
    struct TrieNode {
        bool isPathEnd;
        unordered_map<string, TrieNode*> leaves;
        TrieNode() : isPathEnd(false) {}
    };
    TrieNode *root;
};
// @lc code=end

