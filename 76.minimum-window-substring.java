/*
 * @lc app=leetcode id=76 lang=java
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length() || s.isEmpty()) {
            return "";
        }

        int i = 0, j = 0;
        int start = -1, len = Integer.MAX_VALUE;
        int[] m = new int[128];
        Arrays.fill(m, 0);
        for (char c : t.toCharArray()) {
            m[c]++;
        }

        while (j < s.length()) {
            if (isFound(m)) {
                if (j - i < len) {
                    start = i;
                    len = j - i;
                }
                m[s.charAt(i++)]++;
                continue;
            }
            m[s.charAt(j++)]--;
        }
        while (isFound(m)) {
            if (j - i < len) {
                start = i;
                len = j - i;
            }
            m[s.charAt(i++)]++;
        }

        if (start != -1) {
            return s.substring(start, start + len);
        }
        return "";
    }
    private boolean isFound(int[] m) {
        for (int i : m) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }
}

/*

## Summary
The `minWindow` method finds the minimum window substring in a given string `s` that contains all the characters from another string `t`.

## Example Usage
```java
Solution solution = new Solution();
String s = "ADOBECODEBANC";
String t = "ABC";
String result = solution.minWindow(s, t);
System.out.println(result); // Output: "BANC"
```

## Code Analysis
### Inputs
- `s` (String): The input string from which the minimum window substring needs to be found.
- `t` (String): The target string that contains the characters that need to be present in the minimum window substring.
___
### Flow
1. Check if the length of `s` is less than the length of `t` or if `s` is empty. If either of these conditions is true, return an empty string.
2. Initialize variables `i` and `j` to 0, which represent the start and end indices of the window.
3. Initialize variables `start` and `len` to -1 and `Integer.MAX_VALUE` respectively. These variables will store the start index and length of the minimum window substring.
4. Create an array `m` of size 128 to store the frequency of characters in `t`. Initialize all elements of `m` to 0 using `Arrays.fill()`.
5. Iterate over each character `c` in `t` and increment the corresponding element in `m` by 1.
6. Start a while loop that continues until `j` reaches the end of `s`.
   - Check if the characters in `s` form a valid window (i.e., all characters in `t` are present in the window).
     - If the window is valid, check if the current window length is smaller than the previously found minimum window length. If it is, update `start` and `len` with the current window indices.
     - Increment the frequency of the character at index `i` in `m` and move the window by incrementing `i`.
     - Continue to the next iteration of the loop.
   - If the window is not valid, decrement the frequency of the character at index `j` in `m` and expand the window by incrementing `j`.
7. Start another while loop that continues until a valid window is found or `i` reaches the end of `s`.
   - Check if the characters in `s` form a valid window.
     - If the window is valid, check if the current window length is smaller than the previously found minimum window length. If it is, update `start` and `len` with the current window indices.
     - Increment the frequency of the character at index `i` in `m` and move the window by incrementing `i`.
8. Check if a valid minimum window substring was found (i.e., `start` is not -1). If it was found, return the substring of `s` from `start` to `start + len`. Otherwise, return an empty string.
___
### Outputs
- The method returns a string that represents the minimum window substring in `s` that contains all the characters from `t`. If no such window exists, an empty string is returned.
___


## Summary
The `isFound` method checks if all the elements in the input array `m` are zero or negative.

## Example Usage
```java
Solution solution = new Solution();
int[] m = {0, -1, -2, 0};
boolean result = solution.isFound(m);
System.out.println(result); // Output: true
```

## Code Analysis
### Inputs
- `m` (int[]): an array of integers representing the frequency of characters in a string.
___
### Flow
1. Iterate through each element `i` in the array `m`.
2. If any element `i` is greater than zero, return `false`.
3. If all elements in the array are zero or negative, return `true`.
___
### Outputs
- `true` if all elements in the array `m` are zero or negative.
- `false` if any element in the array `m` is greater than zero.
___



 */
// @lc code=end

