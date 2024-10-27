/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Soln 1:
        // if ((root->val > p->val && root->val < q->val) || 
        //     (root->val < p->val && root->val > q->val)) {
        //     return root;
        // }
        // if (root->val > p->val && root->val > q->val) {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // if (root->val < p->val && root->val < q->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // return (root->val == p->val ? p : q);
        
        // Soln 2:
        // if (root->val < p->val && root->val < q->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // if (root->val > p->val && root->val > q->val) {
        //     return lowestCommonAncestor(root->left, p , q);
        // }
        // return root;
        
        //Soln3:
         TreeNode *curr = root;
         while(1) {
             if (curr->val < p->val && curr->val < q->val) {
                 curr = curr->right;
             } else if (curr->val > p->val && curr->val > q->val) {
                 curr = curr->left;
             } else {
                 break;
             }
         }
         return curr;
    }
};