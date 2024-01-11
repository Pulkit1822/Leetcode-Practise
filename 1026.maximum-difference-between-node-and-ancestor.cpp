/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    using int2=array<int,2>;
    int ans=0;
/**
 * Calculates the minimum and maximum values in a binary tree.
 *
 * @param root The root node of the binary tree.
 *
 * @return A pair of integers representing the minimum and maximum values in the tree.
 *
 * @throws None
 */
std::pair<int, int> dfs(TreeNode* root) {
    if (!root) {
        return {std::numeric_limits<int>::max(), std::numeric_limits<int>::min()};
    }
    
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    
    int x = root->val;
    
    int min_ = std::min({x, left.first, right.first});
    int max_ = std::max({x, left.second, right.second});
    ans = std::max({ans, std::abs(x - min_), std::abs(x - max_)});
    
    return {min_, max_};
}
/**
 * Calculate the maximum difference between any node value and its ancestor value in a binary tree.
 *
 * @param root The root node of the binary tree.
 *
 * @return The maximum difference between any node value and its ancestor value.
 *
 * @throws None
 */
int maxAncestorDiff(TreeNode* root) {
    int ans = 0;
    stack<pair<TreeNode*, pair<int, int>>> stk;
    stk.push({root, {root->val, root->val}});
    
    while (!stk.empty()) {
        auto node = stk.top().first;
        auto minMax = stk.top().second;
        stk.pop();
        
        int minVal = min(minMax.first, node->val);
        int maxVal = max(minMax.second, node->val);
        ans = max(ans, maxVal - minVal);
        
        if (node->left) {
            stk.push({node->left, {minVal, maxVal}});
        }
        if (node->right) {
            stk.push({node->right, {minVal, maxVal}});
        }
    }
    
    return ans;
}
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// @lc code=end

