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
    int getDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(getDepth(root->right), getDepth(root->left)) + 1;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return NULL;
        
        int right_depth = getDepth(root->right);
        int left_depth = getDepth(root->left);
        
        if (right_depth == left_depth)
            return root;
        
        if (right_depth > left_depth) 
            return subtreeWithAllDeepest(root->right);
        
        else 
            return subtreeWithAllDeepest(root->left);
    }
};