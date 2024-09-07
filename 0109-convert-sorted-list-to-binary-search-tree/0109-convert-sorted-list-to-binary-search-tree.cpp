/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(vector<int>&ans,int start,int end){
        if(start==end)
            return new TreeNode(ans[start]);
        if(start>end)
            return nullptr;
        int mid=start+(end-start)/2;
        TreeNode* currnode=new TreeNode(ans[mid]);
        currnode->left=helper(ans,start,mid-1);
        currnode->right=helper(ans,mid+1,end);
        return currnode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
            TreeNode* node=helper(ans,0,ans.size()-1);
        return node;
        
    }
};