/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int val=arr[i];
            for(int k=i+1;k<n;k++){
                val^=arr[k];
                if(val==0){
                    ans+=k-i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

