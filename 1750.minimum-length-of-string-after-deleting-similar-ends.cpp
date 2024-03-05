/*
 * @lc app=leetcode id=1750 lang=cpp
 *
 * [1750] Minimum Length of String After Deleting Similar Ends
 */

// @lc code=start
class Solution {
public:
    int minimumLength(const string& s)
    {
        int left{0}, right{static_cast<int>(s.size() - 1)};
        while (left < right) {
            if (s[left] != s[right])
                break;
            while (left < right && s[left] == s[left + 1])
                left++;
            while (left < right && s[right] == s[right - 1])
                right--;

            left++;
            right--;
        }

        return right < left ? 0 : right - left + 1;
    }

};
// @lc code=end

