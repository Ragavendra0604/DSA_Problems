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
    public boolean isSymmetric(TreeNode root) {
        return f(root.left,root.right);
    }

    boolean f(TreeNode nodel,TreeNode noder){
        if(nodel==null || noder==null) return nodel==noder;
        return nodel.val==noder.val && f(nodel.left,noder.right) && f(nodel.right,noder.left);
    }
}