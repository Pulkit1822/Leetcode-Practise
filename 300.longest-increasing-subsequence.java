/*
 * @lc app=leetcode id=300 lang=java
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public int lengthOfLIS(int[] nums) {
    int n = nums.length;
    int[] dp = new int[n];
    int len = 0;
    
    for (int num : nums) {
        int i = Arrays.binarySearch(dp, 0, len, num);
        
        if (i < 0) {
            i = -(i + 1);
        }
        
        dp[i] = num;
        
        if (i == len) {
            len++;
        }
    }
    
    return len;
}
}
// @lc code=end

