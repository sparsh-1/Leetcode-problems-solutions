// https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans{{1}};
        if (numRows == 1)
            return ans;
        for (int i = 1; i < numRows; i++) {
            vector<int> des(ans[i - 1].size() + 1, 1);
            for (int j = 1; j < des.size() - 1; j++) {
                des[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(des);
        }
        return ans;
    }
};