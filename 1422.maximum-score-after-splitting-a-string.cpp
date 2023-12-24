/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start

class Solution {
public:
int maxScore(string s) {
    int oneCount = 0;
    int zeroCount = 0;
    int score = -1;
    int currScore;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            ++oneCount;
        }
    }
    
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '0') {
            ++zeroCount;
        } else {
            --oneCount;
        }
        
        currScore = zeroCount + oneCount;

        if (currScore > score) {
            score = currScore;
        }
    }

    return score;
}
};
// @lc code=end

