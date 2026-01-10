package January2026;

import java.util.List;

public class SmallestSubtreewithalltheDeepestNodes {
    
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
    int maxDepth = 0;
    public TreeNode subtreeWithAllDeepest(TreeNode root) {

        List<TreeNode> deepest = new ArrayList<>();
        findDepth(root, 0);
        collect(root, 0, deepest);

        TreeNode ans = deepest.get(0);
        for(int i = 0; i < deepest.size(); i++){
            ans = lca(root, ans, deepest.get(i));
        }
        return ans;
    }
    public void findDepth(TreeNode node, int depth){
        if (node == null) return;
        maxDepth = Math.max(maxDepth, depth);

        findDepth(node.left, depth + 1);
        findDepth(node.right, depth + 1);
    }

    public void collect(TreeNode node, int depth, List<TreeNode> deepest){
        if(node == null) return;
        
        if(depth == maxDepth){
            deepest.add(node);
        }

        collect(node.left, depth + 1, deepest);
        collect(node.right, depth + 1, deepest);
    }

    TreeNode lca(TreeNode root, TreeNode a, TreeNode b) {
        if (root == null) return null;
        if (root == a || root == b) return root;

        TreeNode left = lca(root.left, a, b);
        TreeNode right = lca(root.right, a, b);

        if (left != null && right != null) return root;
    
        return (left != null) ? left : right;
    }
}