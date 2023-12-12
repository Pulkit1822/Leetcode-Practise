/*
 * @lc app=leetcode id=238 lang=java
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int result[] = new int[nums.length];
        
        for(int i = 0, product = 1; i < nums.length; i++){
            result[i] = product;
            product *= nums[i];
        }

        for(int i = nums.length - 1, product = 1; i >= 0; i--){
            result[i] *= product;
            product *= nums[i];
        }

        return result;
    }
}
// @lc code=end

