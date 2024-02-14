/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
class Solution {
public:
#include <vector>

/**
 * Rearranges the array by alternating positive and negative numbers.
 * 
 * @param nums The input vector of integers
 * @return The rearranged vector of integers
 */
std::vector<int> rearrangeArray(std::vector<int>& nums) {
    std::vector<int> res;
    int n = nums.size();
    int i = 0;
    int j = 0;
    while (i < n && j < n) {
        while (i < n && nums[i] < 0)
            i++;

        while (j < n && nums[j] > 0)
            j++;

        res.push_back(nums[i++]);
        res.push_back(nums[j++]);
    }

    return res;
}
};
// @lc code=end

