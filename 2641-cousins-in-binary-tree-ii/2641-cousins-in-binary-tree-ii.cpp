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
    void bfs(TreeNode* root,map<int,long long>&levels,map<TreeNode*,int>&parentsum){
        int level=0;
        queue<TreeNode*>q;
        int sum;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            sum=0;
            while(sz--){
                auto node=q.front();
                int temp=0;
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                    temp+=node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    temp+=node->right->val;
                }
                parentsum[node]=temp;
            }
            levels[level]=sum;
            level++;
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        map<int,long long>levels;
        map<TreeNode*,int>parentsum;
        bfs(root,levels,parentsum);
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,nullptr});
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                TreeNode* node=x.first;
                TreeNode* parent=x.second;
                q.pop();
                if(node->left)
                    q.push({node->left,node});
                if(node->right)
                    q.push({node->right,node});
                if(level==0||level==1){
                    node->val=0;
                }
                else{
                    int totalsum=levels[level];
                    node->val=totalsum-parentsum[parent];
                }
            }
            level++;
        }
        return root;
        
        
    }
};