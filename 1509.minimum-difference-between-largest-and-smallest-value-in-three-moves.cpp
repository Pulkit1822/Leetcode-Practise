/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int len = nums.size();
    if (len <= 4) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    return min({
        nums[len - 4] - nums[0],
        nums[len - 3] - nums[1],
        nums[len - 2] - nums[2],
        nums[len - 1] - nums[3]
    });
    }
};
// @lc code=end

