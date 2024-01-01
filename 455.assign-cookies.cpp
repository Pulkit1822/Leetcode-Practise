/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start


class Solution {
public:
/**
 * Finds the maximum number of content children that can be satisfied based on the
 * given greed factor and size of cookies.
 * 
 * @param g The vector of greed factors.
 * @param s The vector of cookie sizes.
 * @return The maximum number of content children that can be satisfied.
 */
int findContentChildren(vector<int>& g, vector<int>& s) {
    // Sort the vectors in ascending order
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // Initialize pointers to track the current greed factor and cookie size
    int g_pointer = 0;
    int s_pointer = 0;

    // Iterate through the vectors
    while (g_pointer < g.size() && s_pointer < s.size()) {
        // If the current greed factor can be satisfied with the current cookie size,
        // move to the next greed factor
        if (g[g_pointer] <= s[s_pointer]) {
            g_pointer++;
        }
        // Move to the next cookie size
        s_pointer++;
    }

    // Return the number of content children that can be satisfied
    return g_pointer;
}
};

// @lc code=end

