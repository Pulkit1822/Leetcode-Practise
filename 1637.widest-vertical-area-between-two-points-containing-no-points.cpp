/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        int L = points.size();
        // y-coordinate of a point does not matter in width
        std::vector<int> arr(L);
        
        for(int i = 0; i < L; i++) {
            arr[i] = points[i][0];
        }

        std::sort(arr.begin(), arr.end());

        int diff = INT_MIN;

        for(int i = 1; i < L; i++) {
            if((arr[i] - arr[i-1]) > diff) {
                diff = arr[i] - arr[i-1];
            }
        }

        return diff;
    }
};

// @lc code=end

