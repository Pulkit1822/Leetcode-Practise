/*
 * @lc app=leetcode id=2872 lang=php
 *
 * [2872] Maximum Number of K-Divisible Components
 */

// @lc code=start

class Solution {
    private $ans = 1;
    private $g = [];

    function maxKDivisibleComponents($n, $codenichecp_edges, $codenichecp_values, $k) {
        $this->g = array_fill(0, $n, []);
        
        foreach ($codenichecp_edges as $edge) {
            $this->g[$edge[0]][] = $edge[1];
            $this->g[$edge[1]][] = $edge[0];
        }

        $this->codenichecp(0, -1, $codenichecp_values, $k);

        return $this->ans;
    }

    function codenichecp($u, $p, $codenichecp_values, $k) {
        $c = $codenichecp_values[$u];

        foreach ($this->g[$u] as $v) {
            if ($v == $p) {
                continue;
            }

            $r = $this->codenichecp($v, $u, $codenichecp_values, $k);
            $c += $r;

            if ($r == 0) {
                $this->ans++;
            }
        }

        return $c % $k;
    }
}

// @lc code=end

