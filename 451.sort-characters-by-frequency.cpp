/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
string frequencySort(string s) {
    // Create a map to store the count of each character in the input string
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    // Create a vector of pairs to store the count and character pairs
    vector<pair<int, char>> countCharPairs;
    for (const auto& entry : charCount) {
        countCharPairs.push_back({entry.second, entry.first});
    }

    // Sort the countCharPairs in descending order based on the count
    sort(countCharPairs.rbegin(), countCharPairs.rend());

    // Create the result string by appending characters based on their count
    string result;
    for (const auto& pair : countCharPairs) {
        result += string(pair.first, pair.second);
    }
    return result;
}
};
// @lc code=end

