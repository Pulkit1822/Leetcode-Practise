/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */

// @lc code=start

//The implementation in this code uses dynamic programming to solve the problem of compressing a string to the smallest size by removing at most k characters. The 2D dynamic programming array arr is used to store the minimum length of compressed string achievable at each step, where arr[i][j] represents the minimum length after processing the first i characters and removing j characters. The nested loops consider all substrings and possible removals, updating the array with minimum compression lengths considering the count of consecutive characters and the additional length incurred when encoding these counts (1 extra character for 2-9 repetitions, 2 for 10-99, and 3 for 100 or more). The final result is the value at arr[length][k], which gives the length of the optimally compressed string after considering the entire string and up to k removals.
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
// This function calculates the length of the optimal compression of a given string 's' 
// by removing at most 'k' characters.

/**
 * Calculates the length of the optimal compression of a given string,
 * considering the maximum number of characters that can be removed.
 *
 * @param s The string to compress.
 * @param k The maximum number of characters that can be removed.
 * @return The length of the optimal compression.
 */
int getLengthOfOptimalCompression(const std::string& s, int k) {
    // Get the length of the string
    int length = static_cast<int>(s.length());

    // Initialize a 2D vector with default values
    std::vector<std::vector<int>> arr(length + 1, std::vector<int>(k + 2, length + 1));

    // Set default values for the 2D vector
    for (int i = 0; i <= length; i++) {
        for (int j = 0; j <= k + 1; j++) {
            arr[i][j] = length + 1;
        }
    }

    // Set initial value for the base case
    arr[0][0] = 0;

    // Iterate through each character in the string
    for (int i = 1; i <= length; i++) {
        // Iterate through each possible number of characters to remove
        for (int j = 0; j <= k; j++) {
            int count = 0;
            int forRemove = 0;

            // Calculate the optimal compression length for each substring
            for (int q = i; q <= length; q++) {
                // Count the number of characters that are the same as the current character
                if (s[i - 1] == s[q - 1])
                    count++;
                else
                    forRemove++;

                // Check if the number of characters to remove is within the limit
                if (j + forRemove <= k) {
                    int l = arr[i - 1][j] + 1;
                    // Add additional length based on the count of consecutive characters
                    if (count >= 100)
                        l += 3;
                    else if (count >= 10)
                        l += 2;
                    else if (count >= 2)
                        l += 1;
                    // Update the minimum length of the compression for the current substring
                    arr[q][j + forRemove] = std::min(arr[q][j + forRemove], l);
                } else {
                    break;
                }
            }
        }
    }

    // Return the length of the optimal compression
    return arr[length][k];
}
};



// @lc code=end

