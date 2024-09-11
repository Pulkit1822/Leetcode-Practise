/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 0;
        while(start or goal){
            ans += ((start % 2) != (goal % 2));
            start /= 2;
            goal /= 2;
        }
        return ans;
    }
};
// @lc code=end

