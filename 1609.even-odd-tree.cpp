/*
 * @lc app=leetcode id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        int ans= INT_MIN;
        while(q.size()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front(); q.pop();
                if((flag && node->val%2==0)||(flag && ans>=node->val)||
                (!flag && node->val%2!=0)||(!flag && node->val>=ans)) return false;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                ans = node->val;
            }
            flag = !(flag); 
            ans = (flag)?INT_MIN:INT_MAX;
        }
        return true;
    }
};
// @lc code=end

