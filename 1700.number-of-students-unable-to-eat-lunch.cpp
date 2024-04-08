/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
    }

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int countZero = 0;
        int countOne = 0;

        for (int student : students) {
            if (student == 0) {
                countZero++;
            } else {
                countOne++;
            }
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0 && countZero) {
                countZero--;
            } else if (sandwich == 1 && countOne) {
                countOne--;
            } else {
                break;
            }
        }

        return countZero + countOne;
    }
};
// @lc code=end

