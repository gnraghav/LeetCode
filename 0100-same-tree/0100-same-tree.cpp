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
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if (!p && !q) {
//             return 1;
//         }
//         if ((p && !q )|| (q && !p)) return 0;
//         if (p->val != q->val) { return 0;}
//         bool lNode = isSameTree(p->left, q->left);
//         bool rNode = (lNode ? isSameTree(p->right, q->right) : 0);
//         if (!rNode) return 0;
//         return 1;
//     }
// };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
