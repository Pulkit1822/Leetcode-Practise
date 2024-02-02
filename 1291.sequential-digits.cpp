/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution {
public:
#include <vector>
#include <iostream>

// This function generates all sequential digits from 12 to 123456789 and filters the ones within the given range.
std::vector<int> sequentialDigits(int low, int high) {
    // Pre-generated list of sequential digits from 12 to 123456789
    std::vector<int> temp = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,
                             2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,
                             234567,345678,456789,1234567,2345678,3456789,12345678,23456789,
                             123456789};
    std::vector<int> ans; // Initialize a vector to store the sequential digits within the given range
    for (int i = 0; i < temp.size(); i++) { // Iterate through the pre-generated list
        if (temp[i] >= low && temp[i] <= high) { // Check if the sequential digit is within the given range
            ans.push_back(temp[i]); // Add the sequential digit to the result vector if it's within the range
        }
    }
    return ans; // Return the filtered sequential digits within the given range
}
};

/*

## Summary
The `sequentialDigits` function takes in two integers, `low` and `high`, and returns a vector of integers that are sequential digits falling within the range of `low` and `high`.

## Example Usage
```cpp
std::vector<int> result = sequentialDigits(100, 300);
// result = {123, 234}
```

## Code Analysis
### Inputs
- `low` (integer): The lower bound of the range.
- `high` (integer): The upper bound of the range.
___
### Flow
1. Initialize a vector `temp` with pre-defined sequential digits from 12 to 123456789.
2. Initialize an empty vector `ans` to store the sequential digits within the range.
3. Iterate through each element in `temp`.
4. If the element is greater than or equal to `low` and less than or equal to `high`, add it to `ans`.
5. Return `ans`.
___
### Outputs
- `ans` (vector of integers): The sequential digits falling within the range of `low` and `high`.
___
### Time Complexity
- Time complexity: O(n), where `n` is the number of sequential digits in the range.
___
### Space Complexity
- Space complexity: O(n), where `n` is the number of sequential digits in the range.


*/
// @lc code=end

