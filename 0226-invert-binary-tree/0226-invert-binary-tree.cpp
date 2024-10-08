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
    TreeNode* invertTree(TreeNode* root) {
        // if (root) {
        //     invertTree(root->left);
        //     invertTree(root->right);
        //     swap(root->left, root->right);
        // }
        // return root;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
              TreeNode* node = st.top();
              st.pop();
              if (node) {
                  st.push(node->left);
                  st.push(node->right);
                  swap(node->left, node->right);
               }
         }
         return root;
    }
};