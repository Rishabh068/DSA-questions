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
    void inorder(TreeNode*root,vector<int>&nodes){
        if(!root)
            return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    TreeNode* helper(vector<int>nodes,int l,int r){
        if(l>r)
            return nullptr;
        int mid=l+(r-l)/2;
        TreeNode* ele= new TreeNode(nodes[mid]);
        ele->left=helper(nodes,l,mid-1);
        ele->right=helper(nodes,mid+1,r);
        return ele;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nodes;
        inorder(root,nodes);
        TreeNode* newroot=helper(nodes,0,nodes.size()-1);
        return newroot;
        
    }
};