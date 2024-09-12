/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
    public:
        bool check(vector<int>& nums) {
            int n = nums.size();
            int count = 0;
            for(int i = 0; i<n;i++){
                if(nums[i]<nums[(i+1)%n]){
                    count++;
                }
            }
            return count<=1;
            
        }
    };
// @lc code=end

