/*
 * @lc app=leetcode id=446 lang=java
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start


class Solution {
public int numberOfArithmeticSlices(int[] nums) {
    // Map to store the indices of each number
    Map<Integer, List<Integer>> numIndicesMap = new HashMap<>();
    int len = nums.length;
    int[][] dp = new int[len][len];
    int res = 0;

    // Populate the map with number indices
    for (int i = 0; i < len; i++) {
        numIndicesMap.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            // Calculate the previous number in the arithmetic sequence
            long prev = 2L * nums[j] - nums[i];
            // Skip if the previous number exceeds the integer range
            if (prev > Integer.MAX_VALUE || prev < Integer.MIN_VALUE) {
                continue;
            }

            // Get the indices of the previous number
            List<Integer> indices = numIndicesMap.getOrDefault((int) prev, null);
            if (indices != null) {
                for (int k : indices) {
                    // Skip if the index is greater than or equal to j
                    if (k >= j) break;
                    // Calculate the number of arithmetic slices and update dp
                    dp[i][j] += dp[j][k] + 1;
                }
            }
            // Update the result with the number of arithmetic slices ending at index i and j
            res += dp[i][j];
        }
    }
    return res;
}
}
// @lc code=end

