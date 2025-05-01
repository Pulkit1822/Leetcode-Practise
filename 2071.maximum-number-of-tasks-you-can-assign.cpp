/*
 * @lc app=leetcode id=2071 lang=cpp
 *
 * [2071] Maximum Number of Tasks You Can Assign
 */

// @lc code=start
class Solution
{
    public:
        int maxTaskAssign(vector<int> &t, vector<int> &ws, int pills, int s)
        {
            int l = 0, r = min(size(t), size(ws));
            sort(begin(t), end(t));
            sort(begin(ws), end(ws));
            while (l < r)
            {
                int m = (l + r + 1) / 2, p = pills, j = size(ws) - 1, g = 1;
                deque<int> q;
                for (int i = m - 1; i >= 0 && g; --i)
                {
                    while (j >= 0 && j >= size(ws) - m && ws[j] + s >= t[i]) q.push_back(ws[j--]);
                    if (!size(q)) g = 0;
                    else
                    if (q.front() >= t[i]) q.pop_front();
                    else if (--p < 0) g = 0;
                    else q.pop_back();
                }
                if (g) l = m;
                else r = m - 1;
            }
            return l;
        }
};
// @lc code=end

