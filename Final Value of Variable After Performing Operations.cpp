// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Just checked the first or last of each string as +, if it is +, then increment the number
// else decrement it.
// Time Complexityt - O(n), Space Complexity - O(1)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (int i = 0; i < operations.size(); i++)
            if (operations[i][0] == '+' || operations[i][2] == '+')
                ans++;
        return 2 * ans - operations.size();
    }
};