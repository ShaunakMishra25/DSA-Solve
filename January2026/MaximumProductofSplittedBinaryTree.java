package January2026;

public class MaximumProductofSplittedBinaryTree {
    
}
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
    private long totalSum = 0;
    private long maxProduct = 0;
    private static final int MOD = 1_000_000_007;

    public int maxProduct(TreeNode root) {
        totalSum = dfsSum(root);

        dfsProduct(root);

        return (int)(maxProduct % MOD);
    }

    private long dfsSum(TreeNode node) {
        if (node == null) return 0;
        return dfsSum(node.left) + dfsSum(node.right) + node.val;
    }

    private long dfsProduct(TreeNode node) {
        if (node == null) return 0;

        long left = dfsProduct(node.left);
        long right = dfsProduct(node.right);

        long subTreeSum = left + right + node.val;

        long product = subTreeSum * (totalSum - subTreeSum);
        maxProduct = Math.max(maxProduct, product);

        return subTreeSum;
    }
}
