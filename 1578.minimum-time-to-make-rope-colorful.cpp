/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start

class Solution {
public:
/**
 * Calculate the minimum cost of painting a sequence of colors.
 *
 * @param colors A string representing the sequence of colors.
 * @param neededTime A vector of integers representing the time needed to paint each color.
 * @return The minimum cost of painting the sequence of colors.
 */
int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size(); // Get the size of the colors string
    int cost = 0; // Initialize the cost variable to 0

    for (int i = 1; i < n; i++) { // Iterate through each color in the sequence
        if (colors[i] == colors[i - 1]) { // Check if the current color is the same as the previous color
            char currentColor = colors[i]; // Store the current color
            int maxTime = neededTime[i - 1]; // Set the maximum time to the time needed to paint the previous color
            int totalTime = maxTime; // Initialize the total time to the maximum time

            while (i < n && colors[i] == currentColor) { // Continue iterating while the current color is the same as the previous color
                maxTime = max(maxTime, neededTime[i]); // Update the maximum time if the time needed to paint the current color is greater
                totalTime += neededTime[i]; // Add the time needed to paint the current color to the total time
                i++; // Increment the index
            }

            cost += totalTime - maxTime; // Add the difference between the total time and the maximum time to the cost
        }
    }

    return cost; // Return the minimum cost
}
};
// @lc code=end

