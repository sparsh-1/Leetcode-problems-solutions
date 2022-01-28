// https://leetcode.com/problems/min-cost-climbing-stairs/
// Dynamic Programming
// What I have used is that I can come to a particular from the past 2 steps
// i.e (i - 1) or (i - 2), now for the tile where our cost is lower we will be coming from that tile
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i < cost.size(); i++)
            cost[i] += min(cost[i - 1], cost[i - 2]);
        return min(cost.back(), cost[cost.size() - 2]);
    }
};