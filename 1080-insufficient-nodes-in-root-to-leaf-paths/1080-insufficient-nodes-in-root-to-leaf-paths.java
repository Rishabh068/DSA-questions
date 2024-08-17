/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if(root == null) {
            return null;
        }    
        boolean res = helper(root , limit , 0);
        return res == false ? null : root;
    }
    public boolean helper(TreeNode node , int limit , int sum) {
        if(node.left == null && node.right == null) {
            sum += node.val;
            if(sum < limit){
                return false;
            }
            return true;
        }
        boolean left = false, right = false;
        if(node.left != null)
            left = helper(node.left , limit , sum + node.val);
        if(node.right != null)
            right = helper(node.right , limit , sum + node.val);
        if(!left && !right) {
            return false;
        }
        if(!left) {
            node.left = null;
        }
        if(!right) {
            node.right = null;
        }
        return true;
    }
};