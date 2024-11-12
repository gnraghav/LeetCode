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
                              const vector<int>& preorder,
                              const map<int, int>& inorderMap) {
        if (low > high) return nullptr;
        if (index >= preorder.size()) return nullptr;

        int val = preorder[index];
        TreeNode* root = new TreeNode(val);
        index++; // move to the next node to create

        root->left = buildTreeHelper(index, low, inorderMap.at(val) - 1, preorder, inorderMap);
        root->right = buildTreeHelper(index, inorderMap.at(val) + 1, high, preorder, inorderMap);

        return root;
    }

    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int index = 0;
        return buildTreeHelper(index, 0, preorder.size() - 1, preorder, inorderMap);
    }

};