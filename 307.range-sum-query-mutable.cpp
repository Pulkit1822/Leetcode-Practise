/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class BIT { // One-based indexing
    vector<int> bit;
public:
    BIT(int size=0) {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) { // Get sum in range [1..idx]
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    void addValue(int idx, int val) {
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};
class NumArray {
    BIT bit;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->bit = BIT(nums.size());
        this->nums = nums;
        for (int i = 0; i < nums.size(); ++i)
            bit.addValue(i+1, nums[i]);
    }
    void update(int index, int val) {
        int diff = val - nums[index]; // get diff amount of `val` compared to current value
        bit.addValue(index + 1, diff); // add this `diff` amount at index `index+1` of BIT, plus 1 because in BIT it's 1-based indexing
        nums[index] = val; // update latest value of `nums[index]`
    }
    int sumRange(int left, int right) {
        return bit.getSum(right+1) - bit.getSum(left);
    }
};

//github @Pulkit1822

/*
explanation for this code:
The code is a constructor for a class named BIT. This class represents a Binary Indexed Tree (also known as a Fenwick Tree), which is a data structure providing efficient methods for calculation and manipulation of the prefix sums of a list of numbers.
The constructor BIT(int size=0) takes an integer argument size which defaults to 0 if no argument is provided. This argument represents the size of the Binary Indexed Tree.
Inside the constructor, bit.assign(size + 1, 0); is called. Here, bit is a vector of integers that is a member of the BIT class. The assign() function is a method provided by the vector class in C++ which is used to assign new values to the vector elements. This line of code assigns size + 1 elements to the bit vector, all initialized to 0.
The reason for size + 1 instead of size is that Binary Indexed Trees are usually implemented with 1-based indexing, meaning the first element is at position 1, not 0. This is done because of the way the tree is structured and the operations performed on it, which involve bitwise operations on the index. Having a 0 index would complicate these operations.
*/

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
// @lc code=end

