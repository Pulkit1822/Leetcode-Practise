/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
/**
 * This code snippet defines a class Solution that contains a method closeStrings. 
 * The closeStrings method takes two string parameters, word1 and word2, and checks if they are "close" strings.
 * Two strings are considered "close" if they have the same length and the counts of each character in the strings are the same, 
 * regardless of the order of the characters.
 * The method first checks if the lengths of the two words are different, and if so, returns false.
 * Then, it creates two arrays, count1 and count2, to store the count of each character in word1 and word2, respectively.
 * It counts the occurrences of each character in word1 and word2 using a loop.
 * After that, it checks if the counts of characters in the two words are different.
 * If one character count is zero and the other is not, it returns false.
 * Finally, it sorts the character counts in ascending order and checks if the sorted character counts are equal.
 * If they are equal, it returns true, indicating that the two words are "close" strings.
 * Otherwise, it returns false.
 */
class Solution {
public:
    array<int, 26>&  alpha(const string& word, array<bool, 26>& S){
        array<int, 26>  A;
        A.fill(0);
        for(char c: word){
            int i=c-'a';
            S[i]=1;
            A[i]++;
        }
        return A;
    }

bool closeStrings(string& word1, string& word2) {
    // Check if the lengths of the two words are different
    if (word1.length() != word2.length()) {
        return false;
    }

    // Create arrays to store the count of each character in the words
    array<int, 26> count1 = {0};
    array<int, 26> count2 = {0};

    // Count the occurrences of each character in word1
    for (char c : word1) {
        count1[c - 'a']++;
    }

    // Count the occurrences of each character in word2
    for (char c : word2) {
        count2[c - 'a']++;
    }

    // Check if the counts of characters in the two words are different
    for (int i = 0; i < 26; i++) {
        // If one character count is zero and the other is not, return false
        if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {
            return false;
        }
    }

    // Sort the character counts in ascending order
    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());

    // Check if the sorted character counts are equal
    return count1 == count2;
}
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// @lc code=end

