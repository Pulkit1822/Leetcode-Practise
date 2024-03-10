class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(begin(nums1), end(nums1));
        unordered_set<int> result;
        for (auto n : nums2)
            if (s1.count(n))
                result.insert(n);
        return vector<int>(begin(result), end(result));
    }

};