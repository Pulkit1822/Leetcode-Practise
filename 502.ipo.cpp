/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios_base::sync_with_stdio(false);
        int n = profits.size();
        vector<pair<int, int>> minCapital;

        for (int i = 0; i < n; i++)
            minCapital.push_back({capital[i], profits[i]});

        sort(minCapital.begin(), minCapital.end());

        priority_queue<int> maxProfit;
        int j = 0;
        for (int i = 0; i < k; ++i) {
            while (j < n && minCapital[j].first <= w) {
                maxProfit.push(minCapital[j].second);
                j++;
            }

            if (maxProfit.empty())
                break;

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
// @lc code=end

