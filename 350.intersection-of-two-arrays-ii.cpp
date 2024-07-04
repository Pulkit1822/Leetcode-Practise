/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>output;
        int start1=0,start2=0;
        while(start1<n1 && start2<n2){
            if(nums1[start1]==nums2[start2]){
                output.push_back(nums1[start1]);
                start1++;
                start2++;
            }
            else if(nums1[start1]<nums2[start2]){
                start1++;
            }
            else start2++;
        }
        return output;
    }
};
// @lc code=end

