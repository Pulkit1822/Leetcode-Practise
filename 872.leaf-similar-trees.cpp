/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
/**
 * @brief Checks if the leaf values of two binary trees are similar.
 * 
 * This function takes in the root nodes of two binary trees and checks if their leaf values are similar.
 * 
 * @param root1 The root node of the first binary tree.
 * @param root2 The root node of the second binary tree.
 * @return true if the leaf values are similar, false otherwise.
 */
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    // Create vectors to store the leaf values of the binary trees
    std::vector<int> leafValues1, leafValues2;
    
    // Populate the vectors with the leaf values of the binary trees
    getLeafValues(root1, leafValues1);
    getLeafValues(root2, leafValues2);
    
    // Check if the leaf values are similar
    return leafValues1 == leafValues2;
}

    void getLeafValues(TreeNode* node, std::vector<int>& nodeList) {
        if (!node) {
            return;
        }

        if (!node->left && !node->right) {
            nodeList.push_back(node->val);
            return;
        }

        getLeafValues(node->left, nodeList);
        getLeafValues(node->right, nodeList);
    }

};
// @lc code=end

