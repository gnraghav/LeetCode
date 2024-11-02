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
private:
    void fillVecInOrder(TreeNode *root, vector<int>& vec) {
        if (!root) return;
        fillVecInOrder(root->left, vec);
        vec.push_back(root->val);
        fillVecInOrder(root->right, vec);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        vector<int> res;
        fillVecInOrder(root, res);
        return res[k-1];
    }
};