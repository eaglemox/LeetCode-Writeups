/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using namespace std;

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Convert into canonical form (lean left) and compare two tree
        // Time: O(N), Space: O(N)
        convertCanonical(root1);
        convertCanonical(root2);
        return checkEquiv(root1, root2);
    }
private:
    void convertCanonical(TreeNode* root) {
        if (!root) {return;} // base case
        convertCanonical(root->left);
        convertCanonical(root->right);

        if (!root->right) {return;}
        if (!root->left) {
            root->left = root->right;
            root->right = nullptr;
            return;
        }
        if (root->left->val > root->right->val) { // swap child
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }

    bool checkEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {return true;} // reach end
        // either one is null & value unequal
        if (!root1 || !root2 || root1->val != root2->val) {return false;}

        return checkEquiv(root1->left, root2->left) && checkEquiv(root1->right, root2->right);
    }
};
// @lc code=end

