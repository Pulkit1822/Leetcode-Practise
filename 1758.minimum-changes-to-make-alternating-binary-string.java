/*
 * @lc app=leetcode id=1758 lang=java
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
class Solution {
    public int helperFn(char[] str, char currChar) {
        int count = 0;
        for(char ch: str) {
            if(ch != currChar) {
                count++;
            }
            currChar = currChar=='0'?'1':'0';
        }
        return count;
    }

    public int minOperations(String s) {
        int count1 = helperFn(s.toCharArray(), '0');
        int count2 = helperFn(s.toCharArray(), '1');
    
        return Math.min(count1, count2);
    }
}
// @lc code=end

