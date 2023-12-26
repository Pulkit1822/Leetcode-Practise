/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
constexpr int kMod = 1000'000'007;

class Solution {
public:
/**
 * Calculates the number of dice rolls needed to reach a target sum.
 *
 * @param d the number of dice
 * @param f the number of faces on each die
 * @param target the target sum
 *
 * @return the number of possible dice roll combinations that add up to the target sum
 */
int64_t numRollsToTarget(int64_t d, int64_t f, int64_t target) {
  target -= d;
  if (target < 0) {
    return 0;
  }
  if (target == 0) {
    return 1;
  }
  vector<int64_t> dp(target + 1);
  dp[0] = 1;
  int64_t size = 1;
  while (d > 0) {
    size = min(size + f - 1, target + 1);
    --d;
    std::inclusive_scan(dp.begin(), dp.begin() + size, dp.begin());
    for (int64_t i = size - 1; i >= f; --i) {
      dp[i] = (dp[i] + kMod - dp[i - f]) % kMod;
    }
    for (int64_t i = min(f - 1, size - 1); i >= 0; --i) {
      dp[i] %= kMod;
    }
  }
  return dp[target];
}
} 
// @lc code=end

