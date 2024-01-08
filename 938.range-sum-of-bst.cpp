/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start
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
public:
/**
 * Calculates the sum of node values in a binary search tree (BST) that are within a given range.
 * 
 * @param root The root node of the BST.
 * @param low The lower bound of the range.
 * @param high The upper bound of the range.
 * @return The sum of node values within the given range.
 */
int rangeSumBST(TreeNode* root, int low, int high) {
    // Base case: if the root is null, return 0
    if (!root) {
        return 0;
    }
    
    // Check if the current node value is within the given range
    int currentNodeVal = (root->val >= low && root->val <= high) ? root->val : 0;
    
    // Recursively calculate the sum of node values in the left and right subtrees
    int sum = rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    
    // Return the sum of the current node value and the sum of node values in the subtrees
    return currentNodeVal + sum;
}
};
// @lc code=end

