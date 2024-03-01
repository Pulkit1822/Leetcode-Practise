/*
 * @lc app=leetcode id=2864 lang=php
 *
 * [2864] Maximum Odd Binary Number
 */

// @lc code=start
class Solution {
    function maximumOddBinaryNumber($s) {
        $mpp = array();
        for ($i = 0; $i < strlen($s); $i++) {
            $mpp[$s[$i]]++;
        }

        $ans = "";
        for ($i = 0; $i < strlen($s) - 1; $i++) {
            if ($mpp['1'] > 1) {
                $ans .= '1';
                $mpp['1']--;
            } elseif ($mpp['0'] >= 1) {
                $ans .= '0';
                $mpp['0']--;
            }
        }

        $ans .= '1';
        return $ans;
    }
}
// @lc code=end

