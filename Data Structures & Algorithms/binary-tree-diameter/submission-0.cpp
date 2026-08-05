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
    int diameter=0;
    int depth(TreeNode* node){
        if(!node){
            return 0;
        }
        int leftDepth=depth(node->left);
        int rightDepth=depth(node->right);
        diameter=max(diameter,leftDepth+rightDepth);
        return 1+max(leftDepth,rightDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //遍历之后传给树节点需要有左边的最大深度+右边的最大深度
        depth(root);
        return diameter;//这里diameter记录的是所有节点最大的diameter
    }
};