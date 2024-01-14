/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

/**
 * @brief Check if two strings are close.
 * 
 * @param word1 The first word.
 * @param word2 The second word.
 * @return True if the words are close, false otherwise.
 */
static bool closeStrings(const std::string& word1, const std::string& word2) {
    return word1.size() == word2.size() && signature(word1) == signature(word2);
}
/**
 * Calculates the signature of a word.
 * 
 * @param word The word to calculate the signature for.
 * @return The signature of the word as an array of integers.
 */
static std::array<int, 26> signature(const std::string& word) {
    std::array<int, 26> freq = {};
    for (char ch : word) ++freq[ch - 'a'];
    std::array<int, 26> ans = freq;
    std::sort(std::begin(freq), std::end(freq), std::greater<>());
    for (int i = 0, j = 0; i < std::size(ans); ++i)
        if (ans[i]) ans[i] = freq[j++];
    return ans;
}
// @lc code=end

