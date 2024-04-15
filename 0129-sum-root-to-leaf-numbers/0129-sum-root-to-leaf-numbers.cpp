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
    void helper(TreeNode* root,vector<int>&nums,int num){
           if(!root->left&&!root->right){
               nums.push_back(num*10+root->val);
               return ;
           }
        cout<<num<<endl;
        if(root->left)
            helper(root->left,nums,num*10+root->val);
        if(root->right)
            helper(root->right,nums,num*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        vector<int>nums;
        helper(root,nums,0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
        
    }
};