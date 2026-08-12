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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();//比如头节点有两个子节点 正好是一次for,以此类推 
            vector<int> level;
            for(int i=0;i<levelSize;i++){
                TreeNode* node = q.front();
                q.pop();//删除了队头节点，但是node还是指向对头节点的
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
