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
    TreeNode* helper(vector<int>& preorder,int start,int end){
        if(start>end)
         return nullptr;
        if(start==end)
            return new TreeNode(preorder[start]);
        TreeNode *root=new TreeNode(preorder[start]);
        int itr=start+1;
        while(itr<preorder.size()&&preorder[itr]<preorder[start]&&start<=end)
            itr++;
        TreeNode* left=helper(preorder,start+1,itr-1);
        TreeNode* right=helper(preorder,itr,end);
        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* ans=helper(preorder,0,preorder.size()-1);
        return ans;
        
    }
};