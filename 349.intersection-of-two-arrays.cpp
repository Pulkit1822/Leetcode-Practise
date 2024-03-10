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


Define a function 'intersection' that takes in two arrays 'nums1' and 'nums2'
- Create a set 's1' from 'nums1' to store unique elements
- Create an empty set 'result'
- Loop through each element 'n' in 'nums2'
  - If the element exists in 's1', add it to the 'result' set
- Convert the 'result' set back to a vector and return it
