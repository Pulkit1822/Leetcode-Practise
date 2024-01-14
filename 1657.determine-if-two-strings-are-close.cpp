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

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for (char c : word1) {
        freq1[c - 'a']++;
    }

    for (char c : word2) {
        freq2[c - 'a']++;
    }

    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    return freq1 == freq2;
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

