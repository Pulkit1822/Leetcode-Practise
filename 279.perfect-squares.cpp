/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:

// This function calculates the minimum number of perfect squares needed to sum up to a given number n.
int numSquaresHelper(int n, vector<int> &dp){
    // base case: if n is 0, return 0 as it doesn't require any perfect squares
    if(n == 0)
        return 0;

    // if n is negative, return 0 as it's not a valid input
    if(n < 0)
        return 0;

    // if the result for n is already calculated, return it
    if(dp[n] != -1) return dp[n]; 

    int ans = INT_MAX;
    // iterate through all perfect squares less than or equal to n
    for(int i = 1; i * i <= n; ++i){
        // recursively calculate the minimum number of perfect squares for n - i*i
        ans = min(ans, 1 + numSquaresHelper(n - i * i, dp));
    }

    // store the result in the dp array for future use and return the result
    return dp[n] = ans;
}
    int numSquares(int n) {
        vector<int> dp(n + 1, -1); 
        return numSquaresHelper(n, dp) - 1;
        
    }
};
// @lc code=end

