/*
 * @lc app=leetcode id=57 lang=java
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> result = new ArrayList<>();
        int[] n = newInterval;
        List<int[]> j = new ArrayList<>(Arrays.asList(intervals));
        int i = 0;
        int m = n[0];
        int m1 = n[1];

        while (i < j.size()) {
            if (n[0] >= j.get(i)[0] && n[0] <= j.get(i)[1] ||
                    n[1] >= j.get(i)[0] && n[1] <= j.get(i)[1] ||
                    n[1] >= j.get(i)[1] && n[0] <= j.get(i)[0]) {
                if (j.get(i)[0] < m) {
                    m = j.get(i)[0];
                }
                if (j.get(i)[1] > m1) {
                    m1 = j.get(i)[1];
                }
                j.remove(i);
                if (i <= 0) {
                    i = 0;
                } else {
                    i--;
                }
            } else {
                i++;
            }
        }
        int[] s1 = {m, m1};
        j.add(s1);
        j.sort((a, b) -> Integer.compare(a[0], b[0]));

        return j.toArray(new int[j.size()][2]);
    }
}
// @lc code=end

