/*
 * @lc app=leetcode id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
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
    int maxi = INT_MIN;

// This function calculates the infection time for a given binary tree node.
// The infection time is defined as the maximum distance between the start node
// and any other node in the tree.

int calculateInfectionTime(TreeNode* root, int start, bool isStartNode) {
    // Base case: if the current node is null, return 0
    if (root == nullptr) {
        return 0;
    }

    // If the current node is the start node and is the initial start node,
    // calculate the infection time and return -1
    if (root->val == start && isStartNode) {
        maxi = max(maxi, calculateInfectionTime(root, start, false) - 1);
        return -1;
    }

    // Recursively calculate the infection time for the left and right subtrees
    int leftHeight = calculateInfectionTime(root->left, start, isStartNode);
    int rightHeight = calculateInfectionTime(root->right, start, isStartNode);

    // If the infection time for any subtree is negative, it means that the
    // start node is present in that subtree. Calculate the maximum infection
    // time for the subtree and return the minimum height minus 1.
    if (leftHeight < 0 || rightHeight < 0) {
        maxi = max(maxi, abs(leftHeight) + abs(rightHeight));
        return min(leftHeight, rightHeight) - 1;
    }

    // Otherwise, return the maximum height of the left and right subtrees plus 1.
    return max(leftHeight, rightHeight) + 1;
}

    int amountOfTime(TreeNode* root, int start) {
        int height = calculateInfectionTime(root, start, true);
        return maxi;
    }
};
// @lc code=end

