// https://leetcode.com/problems/richest-customer-wealth/
// What I have done here is that for each row calculated the total sum, if it is larger
// than the maximum sum (i.e max account balance), we replace max sum with total sum
// We return the maximum sum.
// Time Complexity - O(m*n), Space Complexity - O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int msum = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int tsum = 0;
            for (int j = 0; j < accounts[i].size(); j++)
                tsum += accounts[i][j];
            msum = max(msum, tsum);
        }
        return msum;
    }
};