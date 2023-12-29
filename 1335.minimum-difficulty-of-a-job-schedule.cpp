/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution {
public:
/**
 * Calculates the minimum difficulty of completing a set of jobs within a given number of days.
 *
 * @param jobs A vector of integers representing the difficulty of each job.
 * @param days The number of days available to complete the jobs.
 *
 * @return The minimum difficulty of completing the jobs within the given number of days.
 *
 * @throws None
 */
int minDifficulty(vector<int>& jobs, int days) {
    // Get the number of jobs
    const int n = (int)jobs.size();
    
    // If there are fewer jobs than days, it is impossible to complete all jobs within the given number of days
    if (n < days) return -1;
    
    // Create two vectors to store the dynamic programming values
    vector<int> dp(n); // dp[i] represents the minimum difficulty of completing jobs[0...i] within d days
    vector<int> old(n); // old[i] stores the previous dp[i-1] value
    
    dp[0] = jobs[0]; // Initialize dp[0] with the difficulty of the first job
    
    // Calculate the maximum difficulty of completing jobs[0...i] for each i
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1], jobs[i]);
    }

    // Iterate through the remaining days
    for (int d = 1; d < days; d++) {
        swap(dp, old); // Set dp as the previous day's values
        
        // Create a stack to store the previous day's best values
        vector<array<int,3>> stk = {{1<<30,1<<30,1<<30}}; // Initialize with a sentinel value
        
        // Iterate through the jobs starting from the current day
        for (int i = d; i < n; i++) {
            int oldBest = old[i-1]; // Initialize oldBest with the previous day's best value
            
            // Remove the elements from the stack that have greater difficulty than the current job
            while (stk.back()[1] <= jobs[i]) {
                oldBest = min(oldBest, stk.back()[0]);
                stk.pop_back();
            }
            
            // Calculate the new best values and update dp[i]
            stk.push_back({oldBest, jobs[i], min(oldBest + jobs[i], stk.back()[2])});
            dp[i] = stk.back()[2];
        }
    }
    
    return dp[n-1]; // Return the minimum difficulty of completing all jobs within the given number of days
}
};
// @lc code=end

