// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (int i = 0; i < operations.size(); i++)
            if (operations[i][0] == '+' || operations[i][2] == '+')
                ans++;
            else
                ans--;
        return ans;
    }
};