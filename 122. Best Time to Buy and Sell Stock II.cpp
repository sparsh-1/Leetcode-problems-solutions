// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Buying the stock at local minima and selling it at the next local maxima will help achieve the answer

// Time Complexity - O(n) Space Complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0, ans = 0;
        while (j < prices.size()) {
            while (j + 1 < prices.size() && prices[j] <= prices[j + 1])
                j++;
            if (j == i) {
                i++, j++;
            }
            else {
                ans += prices[j] - prices[i];
                i = j;
            }
        }
        return ans;
    }
};