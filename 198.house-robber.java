/*
 * @lc app=leetcode id=198 lang=java
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
/**
 * Calculates the maximum amount that can be robbed from a row of houses.
 *
 * @param nums an array representing the amount of money in each house
 * @return the maximum amount that can be robbed
 */
public int rob(int[] nums) {
    int prevMax = 0; // Store the maximum amount that can be robbed up to the previous house
    int currMax = 0; // Store the maximum amount that can be robbed up to the current house
    
    for (int val : nums) {
        int temp = currMax; // Store the current maximum amount temporarily
        currMax = Math.max(prevMax + val, currMax); // Update the current maximum amount that can be robbed
        prevMax = temp; // Update the previous maximum amount for the next iteration
    }
    
    return currMax; // Return the maximum amount that can be robbed
}
}
// @lc code=end

