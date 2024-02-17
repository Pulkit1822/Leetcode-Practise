/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// @lc code=start
class Solution {
public:
long long furthestBuilding(std::vector<int>& heights, long long bricks, int ladders) {
    // Get the number of buildings
    int n = heights.size();
    
    // Create a priority queue to store the height differences
    std::priority_queue<long long> pq;
    
    // Initialize the sum of height differences and the index of the last processed building
    long long sum = 0;
    long long last = -1;
    
    // Iterate through the buildings
    for(int i = 1; i < n; i++){
        // Calculate the height difference between the current and previous building
        long long next = heights[i] - heights[i-1];
        
        // If the height difference is positive, add it to the priority queue and sum
        if(next > 0){
            pq.push(next);
            sum += next;
        }
        
        // If the sum of height differences exceeds the available bricks
        if(sum > bricks){
            // If ladders are available, use a ladder and subtract the largest height difference from the sum
            if(ladders > 0){
                sum -= pq.top();
                pq.pop();
                ladders--;
            }
            // If no ladders are available, return the index of the last processed building
            else return i - 1;
        }
    }
    
    // If all buildings can be reached with the available resources, return the index of the last building
    return n-1;
}
};
// @lc code=end

