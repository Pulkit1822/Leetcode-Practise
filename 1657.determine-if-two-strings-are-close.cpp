/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
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
    if (word1.length() != word2.length()) {
        return false;
    }

    array<int, 26> count1 = {0};
    array<int, 26> count2 = {0};

    for (char c : word1) {
        count1[c - 'a']++;
    }

    for (char c : word2) {
        count2[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {
            return false;
        }
    }

    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());

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

