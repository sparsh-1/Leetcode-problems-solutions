// https://leetcode.com/problems/pascals-triangle/
// Just Done as instructed
// Time Complexity - O(N^2) Space Complexity - O(N)
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


// I have created a vector of vector at the start itself and completed it till level 2. Then done as instructed
// Time Complexity - O(N^2) Space Complexity - O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>(1, 1));
        if (numRows == 1)
            return ans;
        ans[1].push_back(1);
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < ans[i - 1].size(); j++)
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            ans[i].push_back(1);
        }
        return ans;
    }
};