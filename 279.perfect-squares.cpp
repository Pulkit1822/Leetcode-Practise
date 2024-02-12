/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
int numSquaresHelper(int n, vector<int> &dp){
    if(n == 0)
        return 0;
    if(n < 0)
        return 0;
    if(dp[n] != -1) return dp[n]; 

    int ans = INT_MAX;
    for(int i = 1; i * i <= n; ++i){
        ans = min(ans, 1 + numSquaresHelper(n - i * i, dp));
    }

    return dp[n] = ans;
}
    int numSquares(int n) {
        vector<int> dp(n + 1, -1); 
        return numSquaresHelper(n, dp) - 1;
        
    }
};

/*

## Summary
The code snippet is a method called `numSquares` in the `Solution` class. It calculates the minimum number of perfect square numbers that sum up to a given number `n`.

## Example Usage
```cpp
Solution s;
int result = s.numSquares(12);
// result = 3, as 12 can be expressed as 4 + 4 + 4
```

## Code Analysis
### Inputs
- `n`: an integer representing the target number
___
### Flow
1. The method `numSquares` initializes a vector `dp` of size `n + 1` with all elements set to -1.
2. It then calls the helper method `numSquaresHelper` with the target number `n` and the `dp` vector.
3. The `numSquaresHelper` method checks if the target number `n` is already calculated and stored in the `dp` vector. If so, it returns the stored value.
4. If not, it initializes a variable `ans` with the maximum possible value.
5. It then iterates from 1 to the square root of `n` and calculates the minimum number of perfect square numbers needed to sum up to `n` by recursively calling `numSquaresHelper` with the remaining value after subtracting the square of the current number.
6. It updates `ans` with the minimum value obtained from the recursive calls.
7. Finally, it stores the calculated value of `ans` in the `dp` vector for future use and returns it.
___
### Outputs
- The method `numSquares` returns the minimum number of perfect square numbers that sum up to the given target number `n`.
___


*/
// @lc code=end

