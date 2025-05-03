/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            map<int, int> frequencyMap;
            int dominoCount = tops.size();
            int minRotations = INT_MAX;

            for (int i = 0; i < dominoCount; i++) {
                frequencyMap[tops[i]]++;
                frequencyMap[bottoms[i]]++;
            }

            for (auto entry : frequencyMap) {
                int candidate = entry.first;
                int topRotations = 0;
                int bottomRotations = 0;
                bool isValid = true;

                if (entry.second >= dominoCount) {
                    for (int j = 0; j < dominoCount; ++j) {
                        if (tops[j] != candidate && bottoms[j] != candidate) {
                            isValid = false;
                            break;
                        }
                        if (tops[j] == bottoms[j] && tops[j] == candidate) {
                            continue;
                        } else if (tops[j] == candidate) {
                            topRotations++;
                        } else {
                            bottomRotations++;
                        }
                    }
                    if (isValid) {
                        minRotations = min(minRotations, min(topRotations, bottomRotations));
                    }
                }
            }
            return minRotations == INT_MAX ? -1 : minRotations;
        }
    };
// @lc code=end

