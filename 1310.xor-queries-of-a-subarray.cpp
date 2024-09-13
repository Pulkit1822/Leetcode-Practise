/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution {
    public:
        vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
            vector<int> ans;
    
            for(int i = 0; i<queries.size(); i++){
                int first= queries[i][0];
                int second= queries[i][1];
                int num = 0;
                for(int j =first; j<=second; j++){
                    num ^= arr[j];
                }
                ans.push_back(num);
            }
            return ans;
        }
    };
// @lc code=end

