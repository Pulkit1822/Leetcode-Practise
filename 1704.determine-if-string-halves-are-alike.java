/*
 * @lc app=leetcode id=1704 lang=java
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public boolean halvesAreAlike(String str) {
    int n = str.length(); // Get the length of the input string
    int count = 0; // Initialize a count variable to keep track of the number of vowels

    // Iterate through the first half of the string
    for (int i = 0; i < n / 2; i++) {
        if (isVowel(str.charAt(i))) { // Check if the current character is a vowel
            count++; // Increment the count if it is
        }

        if (isVowel(str.charAt(n - i - 1))) { // Check if the corresponding character in the second half is a vowel
            count--; // Decrement the count if it is
        }
    }

    return count == 0; // Return true if the count is 0 (equal number of vowels in both halves), false otherwise
}
/**
 * Checks if a given character is a vowel.
 *
 * @param ch The character to check.
 * @return true if the character is a vowel, false otherwise.
 */
public boolean isVowel(char ch) {
    // Convert the string of vowels to lowercase for case-insensitive comparison
    String vowels = "aeiou";
    
    // Convert the given character to lowercase for case-insensitive comparison
    char lowercaseCh = Character.toLowerCase(ch);
    
    // Check if the lowercase character exists in the string of vowels
    return vowels.indexOf(lowercaseCh) != -1;
}
}
// @lc code=end

