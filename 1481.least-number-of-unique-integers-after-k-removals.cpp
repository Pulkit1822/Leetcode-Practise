/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution {
public:
/**
 * Compare function for sorting pairs based on the second element.
 *
 * @param a pair of integers
 * @param b pair of integers
 *
 * @return true if the second element of a is less than the second element of b, false otherwise
 *
 * @throws None
 */
static bool cmp(const pair<int, int>& a,
                const pair<int, int>& b)
{
    return a.second < b.second;
}
int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int,int> mp;
    for (int num : arr) {
        mp[num]++;
    }
    int uniqueCount = mp.size();
    vector<int> freqCount;
    for (const auto& kv : mp) {
        freqCount.push_back(kv.second);
    }
    sort(freqCount.begin(), freqCount.end());
    int i = 0;
    while (k > 0 && i < freqCount.size() && k >= freqCount[i]) {
        k -= freqCount[i];
        uniqueCount--;
        i++;
    }
    return uniqueCount;
}
};

/*

## Summary
This code implements a function called `findLeastNumOfUniqueInts` that takes a vector of integers `arr` and an integer `k` as input. The function returns the number of unique integers in `arr` after removing `k` occurrences of any integers.

## Example Usage
```cpp
vector<int> arr = {1, 2, 2, 3, 3, 3};
int k = 2;
int result = findLeastNumOfUniqueInts(arr, k);


-> result = 1, as after removing 2 occurrences of integer 3, the remaining unique integers are {1}
```

## Code Analysis
### Inputs
- `arr` (vector<int>): A vector of integers representing the input array.
- `k` (int): An integer representing the number of occurrences to be removed.
___
### Flow
1. Create an unordered map `mp` to store the frequency count of each integer in `arr`.
2. Calculate the number of unique integers in `arr` by getting the size of `mp`.
3. Create a vector `freqCount` to store the frequency counts of each integer in `mp`.
4. Sort the `freqCount` vector in ascending order.
5. Initialize variables `i` and `uniqueCount` to 0.
6. Iterate over the `freqCount` vector while `k` is greater than 0, `i` is less than the size of `freqCount`, and `k` is greater than or equal to the current frequency count at index `i`.
   - Decrement `k` by the current frequency count at index `i`.
   - Decrement `uniqueCount` by 1.
   - Increment `i` by 1.
7. Return the final value of `uniqueCount`.
___
### Outputs
- `uniqueCount` (int): The number of unique integers in `arr` after removing `k` occurrences of any integers.
___


*/
// @lc code=end

