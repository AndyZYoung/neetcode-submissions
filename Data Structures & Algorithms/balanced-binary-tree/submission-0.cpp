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
    int depth_diff=0;
    int depth_sub(TreeNode* node){
        if(!node)return 0;
        int left=depth_sub(node->left);
        int right=depth_sub(node->right);
        depth_diff=max(depth_diff,abs(left-right));
        return 1+max(left,right);//返回这个（当前子树高度）递归才能正常进行，而不是返回depth_dif,depth_dif是全局变量
    }
public:
    bool isBalanced(TreeNode* root) {
        depth_sub(root);
        return depth_diff<=1;//不用先判断root是否为空，就算root为空这里也返回true
        //等价于
        //if(depth_diff<=1)return true;
        //return false;
    }
};