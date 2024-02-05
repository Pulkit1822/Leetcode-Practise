/*
 * @lc app=leetcode id=387 lang=java
 *
 * [387] First Unique Character in a String
 */

// @lc code=start

class Solution {
    public int firstUniqChar(String s) {
        // Create a map to store the frequency of each character in the input string
        Map<Character, Integer> freqMap = new HashMap<>();
        
        // Iterate through the input string and update the frequency map
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }
        
        // Iterate through the input string and find the first unique character
        for (int i = 0; i < s.length(); ++i) {
            if (freqMap.get(s.charAt(i)) == 1) {
                // Return the index of the first unique character
                return i;
            }
        }
        
        // If no unique character is found, return -1
        return -1;
    }
}
// @lc code=end

