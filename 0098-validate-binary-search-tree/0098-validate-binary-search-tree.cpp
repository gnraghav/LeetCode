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
    bool isValidBtree(TreeNode *root, TreeNode*&prev) {
        if (!root) return true;
        if (!isValidBtree(root->left, prev)) return false;
        if (prev && root->val <= prev->val) return false;
        prev = root;
        return isValidBtree(root->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        // if (!root) return true;
        // bool v1 = isValidBST(root->left);
        // bool v2 = isValidBST(root->right);
        // if (!v1 || !v2) return false;
        // if (!root->left && !root->right) return true;
        // if (!root->left && root->right) return (root->right->val > root->val);
        // if (!root->right && root->left) return (root->left->val < root->val);
        // return (root->left->val < root->val && root->right->val > root->val);
        TreeNode* prev = nullptr;
        return isValidBtree(root, prev);
    }
};