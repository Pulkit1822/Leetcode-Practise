/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
int levelOrderTraversal(TreeNode* root)
{
    if (!root) {
        return 0; // Or any other appropriate value to indicate an empty tree
    }

    queue<TreeNode*> q;
    q.push(root);
    
    int leftMost = root->val;

    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode* temp = q.front();
            q.pop();

            if (i == 0) // Processing the first element only
            {
                leftMost = temp->val;
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return leftMost;
}

    int findBottomLeftValue(TreeNode* root) {
        return levelOrderTraversal(root);
    }
};
// @lc code=end

