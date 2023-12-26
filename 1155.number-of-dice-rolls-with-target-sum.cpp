/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
constexpr int kMod = 1000'000'007;

class Solution {
public:
<<<<<<<<<<<<<  ✨ Codeium AI Suggestion  >>>>>>>>>>>>>>
/**
 * Calculates the number of dice rolls needed to reach a target sum.
 *
 * @param d the number of dice
 * @param f the number of faces on each die
 * @param target the target sum
 *
 * @return the number of possible dice roll combinations that add up to the target sum
 */
-int numRollsToTarget(int d, int f, int target) {
-  // Adjust the target to account for the number of dice rolled
+int64_t numRollsToTarget(int64_t d, int64_t f, int64_t target) {
  target -= d;
-  // If the adjusted target is negative, there are no possible combinations
  if (target < 0) {
    return 0;
  }
-  // If the adjusted target is 0, there is only one possible combination (all dice show 1)
  if (target == 0) {
    return 1;
  }
-  // Initialize a dynamic programming array to store the number of combinations for each sum
  vector<int64_t> dp(target + 1);
  dp[0] = 1;
-  int size = 1;
+  int64_t size = 1;
  while (d > 0) {
-    // Calculate the maximum size of the dynamic programming array for the current number of dice rolled
    size = min(size + f - 1, target + 1);
    --d;
-    // Perform an inclusive scan on the dynamic programming array to calculate the number of combinations for each sum
    std::inclusive_scan(dp.begin(), dp.begin() + size, dp.begin());
-    // Update the dynamic programming array using the recurrence relation
-    for (int i = size - 1; i >= f; --i) {
+    for (int64_t i = size - 1; i >= f; --i) {
      dp[i] = (dp[i] + kMod - dp[i - f]) % kMod;
    }
-    // Reduce the values in the dynamic programming array to modulo kMod
-    for (int i = min(f - 1, size - 1); i >= 0; --i) {
+    for (int64_t i = min(f - 1, size - 1); i >= 0; --i) {
      dp[i] %= kMod;
    }
  }
-  // Return the number of combinations for the target sum
  return dp[target];
}
<<<<<  bot-81e1cad1-6ff1-4c48-83f9-3a19099e2458  >>>>>
};
// @lc code=end

