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
    TreeNode* buildTreeHelper(int& index, int low, int high,
                              const vector<int>& postorder,
                              const map<int, int>& mp) {
        if (low > high || index < 0) return nullptr;
        int val = postorder[index];
        TreeNode* root = new TreeNode(val);
        index--;
        root->right = buildTreeHelper(index, mp.at(val)+1, high, postorder, mp);        
        root->left = buildTreeHelper(index, low, mp.at(val)-1, postorder, mp);        

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for (int i=0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        int index = postorder.size()-1;
        return buildTreeHelper(index, 0, inorder.size()-1, postorder, mp);
    }
};