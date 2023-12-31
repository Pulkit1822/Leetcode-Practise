/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
    // Create an unordered map to store the last index of each character encountered
    std::unordered_map<char, int> charmap;
    // Initialize the maximum difference between equal characters to 0
    int maxDiff = 0;

    // Loop through each character in the string
    for (unsigned index = 0; index < s.length(); ++index) {
        char c = s[index];

        // Check if the character has been encountered before
        std::unordered_map<char, int>::iterator it = charmap.find(c);
        if (it != charmap.end()) {
            // Calculate the difference between the current index and the last index of the character
            int diff = index - it->second;
            // Update the maximum difference if the current difference is greater
            if(maxDiff < diff)
                maxDiff = diff;
            // Continue to the next iteration of the loop
            continue;
        }
        
        // Store the current index of the character in the map
        charmap[c] = index;
    }
    
    // Return the maximum difference between equal characters minus 1
    return maxDiff - 1;
}
};
// @lc code=end

