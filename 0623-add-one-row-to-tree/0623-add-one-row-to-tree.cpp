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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
          newroot->left=root;
        return newroot;
        }
        int currdepth=1;
        q.push(root);
        while(!q.empty()&&currdepth!=depth-1){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            currdepth++;
            
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            TreeNode* dummy1=new TreeNode(val);
            TreeNode* dummy2=new TreeNode(val);
            if(node->left)
                dummy1->left=node->left;
            if(node->right)
                dummy2->right=node->right;
            node->left=dummy1;
            node->right=dummy2;
            
        }
        return root;
        
    }
};