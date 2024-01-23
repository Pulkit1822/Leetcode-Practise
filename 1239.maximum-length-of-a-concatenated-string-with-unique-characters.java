/*
 * @lc app=leetcode id=1239 lang=java
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
public int solve(String[] strs, int no, int[] a, int index, int c) {
    // Base case: if index is equal to c, return 0
    if (index == c) {
        return 0;
    }
    
    // Calculate the bitwise AND of no and a at the given index
    int x = no & a[index];
    
    // If the result of the bitwise AND is 0, return the maximum of adding the length of the current string to the result of two recursive calls
    if (x == 0) {
        return Math.max(
            strs[index].length() + solve(strs, no ^ a[index], a, index + 1, c), 
            solve(strs, no, a, index + 1, c)
        );
    } else {
        // If the result of the bitwise AND is not 0, make a recursive call without adding the length of the current string
        return solve(strs, no, a, index + 1, c);
    }
}
public int maxLength(List<String> arr) {
    // Create an array to store bit masks for each string, and initialize count and uniqueStrings array
    int[] bitMasks = new int[arr.size()];
    int count = 0;
    String[] uniqueStrings = new String[bitMasks.length];
    
    // Iterate through each string in the input list
    for (String s : arr) {
        int bitmask = 0;  // Initialize bit mask for the current string
        boolean isUnique = true;  // Initialize flag to track uniqueness of characters
        
        // Iterate through each character in the string
        for (char ch : s.toCharArray()) {
            int charIndex = ch - 'a';  // Calculate the index of the character
            int charMask = 1 << charIndex;  // Create a mask for the character
            
            // Check if the character has already occurred in the string
            if ((bitmask & charMask) > 0) {
                isUnique = false;  // If character is not unique, set flag to false and break the loop
                break;
            }
            bitmask |= charMask;  // Update the bitmask with the current character
        }
        
        // If the string has unique characters, store the bitmask and string in their respective arrays
        if (isUnique) {
            bitMasks[count] = bitmask;
            uniqueStrings[count++] = s;
        }
    }
    
    // Call the solve method to find the maximum length of a combination of unique strings
    return solve(uniqueStrings, 0, bitMasks, 0, count);
}
}
// @lc code=end

