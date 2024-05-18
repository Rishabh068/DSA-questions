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
    int helper(TreeNode* root,int &minmoves){
        if(root==nullptr){
          return 0;
        }
        int leftChild=helper(root->left,minmoves);
        int rightChild=helper(root->right,minmoves);
        minmoves+=abs(leftChild)+abs(rightChild);
       return root->val+leftChild+rightChild-1;
       
        
            
    }
    int distributeCoins(TreeNode* root) {
        int minmoves=0;
        int x=helper(root,minmoves);
        return minmoves;
        
    }
};