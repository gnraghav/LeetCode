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
//     int dleft(TreeNode* root) {
//         if (!root) return 0;
//         int l = dleft(root->left);
//         int r = dleft(root->right);
//         return max(l,r)+1;
//     }

//     int dright(TreeNode* root) {
//         if (!root) return 0;
//         int l = dleft(root->left);
//         int r = dleft(root->right);
//         return max(l,r)+1;  
//     }
    
    int dTree(TreeNode* root, int& d) {
        if (!root) return 0;
        int l = dTree(root->left, d);
        int r = dTree(root->right, d);
        d  = max(d, l+r);
        return max(l,r)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        // int l = dleft(root->left);
        // int r = dright(root->right);
        int d = 0;
        dTree(root, d);
        return d;
    }
};