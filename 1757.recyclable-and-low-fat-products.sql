/*
 * @lc app=leetcode id=1757 lang=mysql
 *
 * [1757] Recyclable and Low Fat Products
 */

// @lc code=start

select product_id from Products 
where low_fats = 'Y' and recyclable = 'Y';

// @lc code=end