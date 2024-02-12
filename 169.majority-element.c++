/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
int majorityElement(vector<int>& nums) {
    // Initialize the candidate as the first element in the array
    int candidate = nums[0];
    // Initialize the count of the candidate as 1
    int count = 1;

    // Iterate through the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
        // If the current element is the same as the candidate, increment the count
        if (nums[i] == candidate) {
            count++;
        } else {
            // If the current element is different from the candidate, decrement the count
            count--;
            // If the count becomes 0, update the candidate to the current element and reset the count to 1
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    // The candidate at the end of the iteration is the majority element
    return candidate;
}
};
// @lc code=end

