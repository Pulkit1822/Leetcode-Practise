/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:    
int countSubstrings(string& s) {
    int n = s.size(); // get the length of the input string
    int ans = 0; // initialize the count of palindromic substrings
    int N = 2 * n; // define the maximum possible length of a palindrome centered at each character
    
    // loop through all possible palindrome centers
    for (int i = 0; i < N; i++) {
        int left = i / 2; // calculate the left pointer of the potential palindrome
        int right = i / 2 + (i & 1); // calculate the right pointer of the potential palindrome
        
        // expand the potential palindrome and count all valid palindromes
        while (left >= 0 && right < n && s[left] == s[right]) {
            ans++; // increase the count of palindromic substrings
            left--; // move the left pointer to the left
            right++; // move the right pointer to the right
        }
    }
    
    return ans; // return the total count of palindromic substrings
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

