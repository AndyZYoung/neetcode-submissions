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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){//都为空
            return true;
        }
        if(!p || !q){//因为不是都为空，所以这里说的是有一个是空 或的逻辑是有真则为真，全假才为假
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        bool leftSame = isSameTree(p->left, q->left);//递归遍历
        bool rightSame = isSameTree(p->right, q->right);
        return leftSame && rightSame;
    }
};
