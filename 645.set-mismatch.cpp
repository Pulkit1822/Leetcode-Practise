/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
#include <vector>
#include <cmath>

std::vector<int> findErrorNums(const std::vector<int>& nums) {
    // Calculate the expected sum if the array had no errors
    int n = nums.size();
    int sum = (n * (n + 1))/2;

    // Calculate the expected sum of squares if the array had no errors
    long long sqr_sum = 0;
    for(int i = 1; i <= n; i++) sqr_sum += i * i;

    // Calculate the actual sum and sum of squares of the given array
    int arr_sum = 0;
    long long arr_sqr_sum = 0;
    for(int i = 0; i < n; i++){
        arr_sum += nums[i];
        arr_sqr_sum += (nums[i] * nums[i]);
    }

    // Calculate the difference between the expected and actual sums
    int sum_diff = arr_sum - sum;
    int sqr_sum_diff = arr_sqr_sum - sqr_sum;

    // Calculate the missing and duplicate numbers using the differences
    int missing = static_cast<int>((sqr_sum_diff - (sum_diff * sum_diff)) / (2 * sum_diff));
    int duplicate = sum_diff + missing;

    return {duplicate , missing};
}
};
// @lc code=end

