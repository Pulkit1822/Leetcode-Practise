/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start

class Solution {
public:
// Refactored the largestDivisibleSubset function to improve readability and maintainability.

vector<int> largestDivisibleSubset(vector<int>& arr) {
    
    // Sort the input array
    sort(arr.begin(), arr.end());
    
    // Initialize two arrays to track the length of the largest divisible subset and the index of the previous element
    vector<int> lis(arr.size(), 1);
    vector<int> prevIdx(arr.size(), -1);
    
    // Initialize variables to track the maximum length and the index of the maximum length
    int maxLength = 0;
    int maxIndex = 0;
    
    // Iterate through the array to find the length of the largest divisible subset and the index of the previous element
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] % arr[j] == 0 && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prevIdx[i] = j;
            }
        }
        if (lis[i] > maxLength) {
            maxLength = lis[i];
            maxIndex = i;
        }
    }
    
    // Construct the largest divisible subset using the index of the previous element
    vector<int> divisibleSubset;
    while (maxIndex != -1) {
        divisibleSubset.push_back(arr[maxIndex]);
        maxIndex = prevIdx[maxIndex];
    }
    
    // Return the largest divisible subset
    return divisibleSubset;
}

};
// @lc code=end

