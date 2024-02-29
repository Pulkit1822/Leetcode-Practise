/*
 * @lc app=leetcode id=2606 lang=ruby
 *
 * [2606] Find the Substring With Maximum Cost
 */

// @lc code=start

def max_sub_array_sum(a)
    max_so_far = -1.0/0.0
    max_ending_here = 0
    
    a.each do |num|
        max_ending_here += num
        max_so_far = [max_so_far, max_ending_here].max
        
        max_ending_here = 0 if max_ending_here < 0
    end
    
    max_so_far
end

def maximum_cost_substring(s, chars, vals)
    m = {'a' => 1}
    ('b'..'z').each_with_index do |c, i|
        m[c] = i+2
    end
    
    chars.each_char.with_index do |c, i|
        m[c] = vals[i]
    end
// @lc code=end

