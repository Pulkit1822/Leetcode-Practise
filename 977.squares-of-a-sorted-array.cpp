/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        vector<int> result(nums.size());
        int result_index = result.size() - 1;

        while (start <= end) {
            int square1 = nums[start] * nums[start];
            int square2 = nums[end] * nums[end];

            result[result_index--] = (square1 > square2) ? square1 : square2;
            if (square1 > square2) start++;
            else end--;
        }

        return result;
    }

};
// @lc code=end

