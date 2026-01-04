/*
 * @lc app=leetcode id=1390 lang=java
 *
 * [1390] Four Divisors
 */

// @lc code=start
class Solution {
    
    public 

    int findSumOfDivisors(int num){
        int div = 0;
        int sumOfDiv = 0;

        for(int fact = 1; fact*fact <= num; fact++){
            if(num % fact == 0){
                int pairFact = num/fact;
                if(pairFact == fact){
                    div += 1;
                    sumOfDiv += fact;
                }
                else {
                    div += 2;
                    sumOfDiv += (fact + pairFact);
                }
            }
            if(div > 4){
                return 0;
            }
        }
        if(div == 4){
            return sumOfDiv;
        }
        else {
            return 0;
        }
    }
    
    
    int sumFourDivisors(int[] nums) {
        int totalSum = 0;

        for(int num:nums){
            totalSum += findSumOfDivisors(num);

        }



        return totalSum;

    
    }
}
// @lc code=end

