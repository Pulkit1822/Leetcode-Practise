/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution {
public:
// Check if all the strings in the vector can be made equal by rearranging the characters
bool makeEqual(vector<string>& words) {
    // If there is only one word in the vector, it is already equal to itself, so return true
    if (words.size() == 1) {
        return true;
    }

    int n = words.size(); // Number of words in the vector

    int totalCharCount = 0; // Total character count of all the words
    for (const std::string& s : words) {
        totalCharCount += s.length(); // Add the length of each word to the total character count
    }
    if (totalCharCount % n != 0) { // If the total character count is not divisible by the number of words, return false
        return false;
    }

    vector<int> freq(26, 0); // Frequency of each character in the words
    for (const std::string& str : words) { // Iterate over each word
        for (char ch : str) { // Iterate over each character in the word
            freq[ch - 'a']++; // Increment the frequency of the character
        }
    }
    for (int i = 0; i < 26; i++) { // Iterate over each character
        if (freq[i] % n != 0) { // If the frequency of the character is not divisible by the number of words, return false
            return false;
        }
    }
    return true; // All characters can be rearranged to make the words equal
}
};
// @lc code=end

