/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution {
public:
    bool isValidParenthesisString(string s) {
        int openCount = 0, closeCount = 0, starCount = 0;
        
        // Check from left to right
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                openCount++;
            } else if(s[i] == ')') {
                closeCount++;
            } else {
                starCount++;
            }
            
            if(closeCount > openCount + starCount) {
                return false;
            }
        }
        
        openCount = 0;
        closeCount = 0;
        starCount = 0;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ')') {
                openCount++;
            } else if(s[i] == '(') {
                closeCount++;
            } else {
                starCount++;
            }
            
            if(closeCount > openCount + starCount) {
                return false;
            }
        }
        
        return true;
    }

    bool checkValidString(string s) {
        return isValidParenthesisString(s);
    }
};

// @lc code=end

