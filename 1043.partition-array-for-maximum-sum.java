/*
 * @lc app=leetcode id=1043 lang=java
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
import java.util.Arrays;

class Solution {
private int solve(int[] arr, int i, int j, int kk, int[][] dp) {
    // If value already calculated, return it
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    // If i is greater than j, return 0
    if (i > j) {
        return 0;
    }
    // If i is equal to j, return arr[i]
    if (i == j) {
        return arr[i];
    }
    // If j - i + 1 is less than or equal to kk, calculate and return the maximum value within the range
    if (j - i + 1 <= kk) {
        int maxi = 0;
        for (int x = i; x <= j; x++) {
            maxi = Math.max(maxi, arr[x]);
        }
        return (j - i + 1) * maxi;
    }

    int ans = 0;

    // Calculate the maximum value by splitting the range at different positions
    for (int k = i; k + kk - 1 <= j; k++) {
        int leftMax = solve(arr, i, k, kk, dp);
        int rightMax = solve(arr, k + 1, j, kk, dp);
        ans = Math.max(ans, leftMax + rightMax);
    }

    dp[i][j] = ans;
    return ans;
}

public int maxSumAfterPartitioning(int[] arr, int k) {
    int n = arr.length;
public int maxSumAfterPartitioning(int[] arr, int k) {
    // Get the length of the input array
    int n = arr.length;
    
    // Create a new array to store the maximum sum for each position
    int[] dp = new int[n + 1];
    
    // Iterate through the input array to calculate the maximum sum for each position
    for (int i = 1; i <= n; i++) {
        // Initialize the current maximum value
        int curMax = 0;
        
        // Iterate through the previous k elements to find the maximum value
        for (int j = 1; j <= k && i - j >= 0; j++) {
            curMax = Math.max(curMax, arr[i - j]);
            // Update the maximum sum for the current position
            dp[i] = Math.max(dp[i], dp[i - j] + curMax * j);
        }
    }
    
    // Return the maximum sum for the last position
    return dp[n];
}
/*
 
This Java code is a solution to the problem of partitioning an array for maximum sum. The function maxSumAfterPartitioning takes two parameters: an integer array arr and an integer k. The goal is to partition the array into subarrays, each containing at most k elements, and then maximize the sum of these subarrays where each subarray's sum is its maximum element multiplied by the number of elements in the subarray.

The length of the input array is stored in the variable n. A dynamic programming (DP) approach is used to solve this problem, which is why a DP array dp of size n + 1 is created. This array will store the maximum sum that can be obtained for each position in the input array.

The outer loop runs from 1 to n (inclusive), iterating through each position in the input array. For each position i, the inner loop iterates through the previous k elements to find the maximum value. This is done because each subarray can contain at most k elements. The variable curMax is used to keep track of the current maximum value.

Inside the inner loop, curMax is updated to be the maximum of curMax and arr[i - j]. Then, the DP array is updated. dp[i] is set to be the maximum of dp[i] and dp[i - j] + curMax * j. This is because the maximum sum for the current position can be obtained either by keeping the previous maximum sum (dp[i]) or by adding the maximum element in the current subarray (curMax) multiplied by the size of the subarray (j) to the maximum sum for the position i - j.

Finally, after all positions have been considered, the function returns dp[n], which is the maximum sum that can be obtained by partitioning the input array.

 */

