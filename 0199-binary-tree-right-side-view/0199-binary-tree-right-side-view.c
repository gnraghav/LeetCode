/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void 
rightHelper(struct TreeNode *root, int *res, int level, int *size) {
    if (!root) return;
    if (*size < level) {
        res[*size] = root->val;
        *size +=1;
    }
    rightHelper(root->right,res,level+1,size);
    rightHelper(root->left,res,level+1,size);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
     if (!root) {
         *returnSize = 0;
         return NULL;
     }

     int *res = (int *)malloc(sizeof(int)*100);
     *returnSize = 0;
     rightHelper(root, res, 1, returnSize);
     return res;
}