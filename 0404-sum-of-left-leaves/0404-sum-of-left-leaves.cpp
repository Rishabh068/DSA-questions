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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});
        int ans = 0;
        while(s.size()) {
            auto [cur, isLeft] = s.top(); s.pop();
            if(!cur -> left && !cur -> right && isLeft) 
                ans += cur -> val;
            if(cur -> right) s.push({cur -> right, false});
            if(cur -> left) s.push({cur -> left, true});
        }
        return ans;
    }
};