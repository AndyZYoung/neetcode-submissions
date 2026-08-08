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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;//剩下的情况都是
    }//因为这里有递归 不是直接 root=root->left 这种的，所以有额外的辅助空间复杂度
};
