class Solution {
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }
        int prevPrev = 1;
        int prev = 1;
        for (int i = 1; i < s.length(); i++) {
            int curr = 0;
            int singleDigit = s.charAt(i) - '0';
            int twoDigits = (s.charAt(i - 1) - '0') * 10 + singleDigit;
            if (singleDigit >= 1 && singleDigit <= 9) {
                curr += prev;
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                curr += prevPrev;
            }
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
}