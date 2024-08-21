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
    TreeNode *xp=nullptr,*yp=nullptr;
    int xd=-1,yd=-2;
    void dfs(TreeNode* root,int x,int y,TreeNode* parent,int depth){
        if(root==nullptr)
            return;
        if(root->val==x){
            xp=parent;
            xd=depth;
        }
        if(root->val==y){
            yp=parent;
            yd=depth;
        }
       dfs(root->left,x,y,root,depth+1);
        dfs(root->right,x,y,root,depth+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,nullptr,0);
        if(xp!=yp&&xd==yd)
            return true;
        return false;
        
        
        
    }
};