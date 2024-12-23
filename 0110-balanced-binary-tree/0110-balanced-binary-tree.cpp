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
class Solution {
public:
    int isB(TreeNode* root, bool& res) {
        if (!root) return 0;
        int l = isB(root->left, res);
        int r = isB(root->right, res);
        if (abs(l-r)>1) {
            res = false;
        }
        return max(l,r)+1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool res = true;
        isB(root, res);
        return res;
    }
};