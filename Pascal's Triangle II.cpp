// https://leetcode.com/problems/pascals-triangle-ii/
// 1st Approach - Solved using Building whole Pascal triangle
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans{{1}};
        if (rowIndex == 0)
            return ans[0];
        for (int i = 1; i < rowIndex + 1; i++) {
            vector<int> des(ans[i - 1].size() + 1, 1);
            for (int j = 1; j < des.size() - 1; j++) {
                des[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(des);
        }
        return ans[rowIndex];
    }
};

// 2nd Approach - Built only the nth row using formula (n - i - 1) / i
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        if (rowIndex == 0)
            return ans;
        long long product = 1;
        for (int i = 1; i < rowIndex; i++) {
            product = (product * (rowIndex - i + 1)) / i;
            ans[i] = product;
        }
        return ans;
    }
};