/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
public:

// This function calculates the maximum sum of values starting from the given row and column indices in a grid.
int f(int i, int j1, int j2, int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    // If the column indices are out of bounds, return a very large negative value.
    if (j1 < 0 || j2 < 0 || j1 >= col || j2 >= col) {
        return -1e8;
    }

    // If we are at the last row, return the sum of values at the corresponding column indices.
    if (i == row - 1) {
        if (j1 == j2) {
            return grid[i][j1];
        } else {
            return grid[i][j1] + grid[i][j2];
        }
    }

    // If the result for the current indices is already calculated, return it.
    if (dp[i][j1][j2] != -1) {
        return dp[i][j1][j2];
    }

    // Initialize the maximum sum as a very large negative value.
    int maxi = -1e8;
    
    // Iterate through all possible next column indices for both j1 and j2.
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int val = 0;
            // Calculate the sum of values at the current row and column indices.
            if (j1 == j2) {
                val = grid[i][j1];
            } else {
                val = grid[i][j1] + grid[i][j2];
            }
            // Recursively calculate the maximum sum for the next row and update maxi.
            val += f(i + 1, j1 + dj1, j2 + dj2, row, col, grid, dp);
            maxi = max(maxi, val);
        }    
    }
    // Store the calculated maximum sum in the dp table and return it.
    return dp[i][j1][j2] = maxi;
}

// This function calculates the maximum number of cherries that can be picked up while moving from the top-left cell to the bottom-right cell of the grid, and then back to the top-left cell.
int cherryPickup(vector<vector<int>>& grid) {
    int row = grid.size(); // Get the number of rows in the grid
    int col = grid[0].size(); // Get the number of columns in the grid
    vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(col,-1))); // Create a 3D vector for dynamic programming memoization
    return f(0,0,col-1,row,col,grid,dp); // Call the recursive function f to find the maximum cherries that can be picked up
}
};
// @lc code=end

