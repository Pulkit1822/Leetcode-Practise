/*
 * @lc app=leetcode id=300 lang=java
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
/**
 * Calculates the length of the longest increasing subsequence in the given array.
 *
 * @param  nums  an array of integers
 * @return       the length of the longest increasing subsequence
 */
public int lengthOfLIS(int[] nums) {
    // Get the length of the input array
    int n = nums.length;
    
    // Create an array to store the lengths of the increasing subsequences
    int[] dp = new int[n];
    
    // Initialize the length of the longest increasing subsequence to 0
    int len = 0;
    
    // Iterate over each number in the input array
    for (int num : nums) {
        // Use binary search to find the index where the current number should be inserted
        int i = Arrays.binarySearch(dp, 0, len, num);
        
        // If the number is not found, binarySearch returns a negative value
        // We need to convert it to a positive index by taking the bitwise complement and subtracting 1
        if (i < 0) {
            i = -(i + 1);
        }
        
        // Update the value at index i in the dp array with the current number
        dp[i] = num;
        
        // If the current number is inserted at the end of the dp array, update the length of the longest increasing subsequence
        if (i == len) {
            len++;
        }
    }
    
    // Return the length of the longest increasing subsequence
    return len;
}
}
// @lc code=end

