// https://leetcode.com/problems/reshape-the-matrix/
// Just travered the original matrix (if dimensions got matched) and put the values
// accordingly into reshaped matrix
// Time Complexity - O(m*n), Space Complexity - O(m*n)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        int rs = 0, cs = 0;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++) {
                ans[rs][cs++] = mat[i][j];
                if (cs >= c)
                    rs++, cs = 0;
            }
        return ans;
    }
};