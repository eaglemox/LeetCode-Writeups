/*
 * @lc app=leetcode id=1948 lang=cpp
 *
 * [1948] Delete Duplicate Folders in System
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Remove duplicates by serializing the path of each node
        Trie *root = new Trie();
        buildTrie(root, paths);

        unordered_map<string, Trie*> seen;
        markDup(root, seen);

        vector<vector<string>> result;
        returnPath(root, result);
        return result;
    }

private:
    struct Trie {
        string name;
        bool duplicate = false;
        unordered_map<string, Trie*> children;
    };

    void buildTrie(Trie* root, const vector<vector<string>>& paths) {
        for (const auto &path: paths) {
            Trie *curr = root;
            for (const auto &node: path) {
                if (!curr->children.count(node)) { // Have not appeared at current path before
                    curr->children[node] = new Trie(node);
                }
                curr = curr->children[node];
            }
        }
    }

    string markDup(Trie* node, unordered_map<string, Trie*>& seen) {
        string subfolder;
        for (const auto &[name, child]: node->children) {
            subfolder += markDup(child, seen);
        }
        if (subfolder.size()) {
            if (seen.count(subfolder)) {
                seen[subfolder]->duplicate = node->duplicate = true;
            } else {
                seen[subfolder] = node;
            }
        }

        return "(" + node->name + subfolder + ")";
    }

    void returnPath(Trie* root, vector<vector<string>>& ret) {
        vector<string> path;
        for (auto &[name, child]: root->children) {
            if (child->duplicate) {continue;}
            path.push_back(child->name);
            ret.push_back(path);

            // To next level
            for (auto &[nextName, nextChild]: child->children) {
                returnPath(nextChild, ret);
            }
            path.pop_back();
        }
        return;
    }
};
// @lc code=end

