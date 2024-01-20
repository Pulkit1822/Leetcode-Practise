/*
 * @lc app=leetcode id=907 lang=java
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;  // Length of input array
        int[] dp = new int[n];  // Array to store subarray minimums
        Stack<Integer> stack = new Stack<>();  // Stack to keep track of indices
        int modulo = 1000000007;  // Modulo value
        long answer = 0;  // Initialize the answer
    
        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while the current element is less than or equal to the element at the top of the stack
            while (!stack.isEmpty() && arr[i] <= arr[stack.peek()]) {
                stack.pop();
            }
            // Calculate the contribution of the current element to the final answer
            dp[i] = (i - (stack.isEmpty() ? -1 : stack.peek())) * arr[i] + (stack.isEmpty() ? 0 : dp[stack.peek()]) % modulo;
            // Push the current index onto the stack
            stack.push(i);
            // Update the final answer with the contribution of the current element
            answer = (answer + dp[i]) % modulo;
        }
        return (int) answer;  // Return the final answer as integer
    }
    }

// @lc code=end

