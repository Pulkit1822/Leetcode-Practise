/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
public:
// Refactored code to improve readability and maintainability

/**
 * Calculate the maximum profit that can be achieved by scheduling jobs
 * 
 * @param startTime: vector of job start times
 * @param endTime: vector of job end times
 * @param profit: vector of job profits
 * @return maximum profit that can be achieved
 */
int jobScheduling(const vector<int>& startTime, const vector<int>& endTime, const vector<int>& profit) {
    int numJobs = profit.size();
    
    // Create a vector of tuples to store job details (endTime, startTime, profit)
    vector<tuple<int, int, int>> jobs(numJobs);
    
    // Populate the jobs vector with job details
    for (int i = 0; i < numJobs; ++i) {
        jobs[i] = make_tuple(endTime[i], startTime[i], profit[i]);
    }
    
    // Sort the jobs vector based on endTime in ascending order
    sort(jobs.begin(), jobs.end());
    
    // Create a vector to store the maximum profit for each job
    vector<int> dp(numJobs + 1);
    
    // Iterate through each job
    for (int i = 0; i < numJobs; ++i) {
        // Retrieve job details from the tuple
        const auto [jobEndTime, jobStartTime, jobProfit] = jobs[i];
        
        // Find the index of the latest non-conflicting job based on jobStartTime
        int latestNonConflictJobIndex = upper_bound(jobs.begin(), jobs.begin() + i, jobStartTime, [&](int time, const auto& job) -> bool {
            return time < get<0>(job);
        }) - jobs.begin();
        
        // Calculate the maximum profit for the current job by either including it or excluding it
        dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + jobProfit);
    }
    
    // Return the maximum profit that can be achieved
    return dp[numJobs];
}
};
// @lc code=end

