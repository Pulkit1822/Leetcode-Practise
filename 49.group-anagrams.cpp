/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    
    for (string &s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(move(s));
    }
    
    vector<vector<string>> ans;
    ans.reserve(map.size());
    for (auto &it : map) {
        ans.push_back(move(it.second));
    }
    
    return ans;
}
};
// @lc code=end

