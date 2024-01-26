/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
    map<vector<int>, int> mp;
// This function performs a depth-first search to find the number of ways to reach out-of-bounds in a grid
// starting from position (sr, sc) in m x n grid, with mm moves left

long long dfs(int sr, int sc, int m, int n, int mm) {
    // If there are no moves left, check if the current position is out-of-bounds and return 1 if true, 0 if false
    if (mm == 0) {
        return (sr < 0 || sc < 0 || sr >= m || sc >= n);
    }
    // If the current position is out-of-bounds, return 1
    if (sr < 0 || sc < 0 || sr >= m || sc >= n) {
        return 1;
    }
    // If the result for the current position and moves is already calculated, return the cached result
    if (mp.count({sr, sc, mm})) {
        return mp[{sr, sc, mm}];
    }
    // Otherwise, calculate the result using the sum of results from adjacent positions
    long long result = (dfs(sr-1, sc, m, n, mm-1) % mod
                     + dfs(sr+1, sc, m, n, mm-1) % mod
                     + dfs(sr, sc-1, m, n, mm-1) % mod
                     + dfs(sr, sc+1, m, n, mm-1) % mod) % mod;
    // Cache the result for the current position and moves and return the result
    return mp[{sr, sc, mm}] = result;
}
public:
const int mod = 1000000007;

int findPaths(int m, int n, int maxMove, int sr, int sc) {
    // Initialize a 2D vector for dynamic programming
    vector<vector<int>> dp(m, vector<int>(n));
    // Set the starting position to 1
    dp[sr][sc] = 1;
    // Initialize variable to store the total number of paths that lead out of the grid
    int ans = 0;
    // Define the directions for movement (right, down, left, up) using deltas
    vector<int> dirs = {0, 1, 0, -1, 0};
    // Loop over the maximum number of moves
    for (int k = 0; k < maxMove; ++k) {
        // Create a temporary 2D vector to store the updated path counts
        vector<vector<int>> temp(m, vector<int>(n));
        // Loop over each cell in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Loop over the four directions
                for (int d = 0; d < 4; ++d) {
                    // Calculate the new position
                    int ni = i + dirs[d];
                    int nj = j + dirs[d + 1];
                    // If the new position is within the grid
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        // Update the count of paths leading to the new position
                        temp[ni][nj] = (temp[ni][nj] + dp[i][j]) % mod;
                    } else {
                        // If the new position is outside the grid, increment the total count of paths
                        ans = (ans + dp[i][j]) % mod;
                    }
                }
            }
        }
        // Update the dp vector with the temporary results
        dp = temp;
    }
    // Return the total count of paths leading out of the grid
    return ans;
}
};
// @lc code=end

