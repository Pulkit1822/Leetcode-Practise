/*
 * @lc app=leetcode id=2586 lang=csharp
 *
 * [2586] Count the Number of Vowel Strings in Range
 */

// @lc code=start
class Solution {
    // A function that takes an array of strings, 
    // a left index, and a right index as input parameters and 
    // counts the number of strings where the first and last characters are vowels. 
    // Returns the count of such strings.
    public int VowelStrings(string[] words, int left, int right) {
        int c = 0;
        for (int i = left; i <= right; ++i) {
            string s = words[i];
            int n = s.Length;
            if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
                (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u')) {
                c++;
            }
        }
        return c;
    }
}
// @lc code=end

