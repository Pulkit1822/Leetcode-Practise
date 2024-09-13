/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution {
public:
    map<string, bool>mp;
    bool solve(string s1, string s2)
    {
        if(s1 ==s2)
            return true;
        if(s1.length() <= 1)
            return false;
        string temp = s1+""+s2;
        if(mp.find(temp) != mp.end())
            return mp[temp];
        bool flag = false;
        int n = s1.length();
        bool cond1=false, cond2=false;
        for(int i=1; i<=n-1; i++)
        {
            if(solve(s1.substr(0, i), s2.substr(n-i, i)) && (solve(s1.substr(i, n-i), s2.substr(0, n-i))))
                cond1= true;
            if(solve(s1.substr(0, i), s2.substr(0, i)) && (solve(s1.substr(i, n-i), s2.substr(i, n-i))))
                cond2 = true;
            if(cond1 || cond2)
            {
                flag = true;
                break;
            }
        }
        return mp[temp] =flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.length() != s2.length())
            return false;
        if(s1.length() <=1)
            return false;
        return solve(s1, s2);
    }
};
// @lc code=end

