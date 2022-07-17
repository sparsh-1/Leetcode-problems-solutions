// https://leetcode.com/problems/maximal-rectangle/
// I jhave used the same logic of finding maximum area in a histogram, I will consider the first row as base
// first and take height accordingly, then I will move to the second row and so on. i will always take next smaller
// element and previous smaller element to find the area of histogram and store maximum area of the
// submatrix with all 1's.
// Time Complexity - O(m * n || rows * columns) Space Complexity - (col.size())
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> height(matrix[0].size());
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            stack<int> s;
            vector<int> pse;
            for (int i = 0; i < height.size(); i++) {
                if (s.empty()) {
                    pse.push_back(-1);
                    s.push(i);
                }
                else {
                    while (!s.empty() && height[s.top()] >= height[i])
                        s.pop();
                    if (s.empty())
                        pse.push_back(-1);
                    else
                        pse.push_back(s.top());
                    s.push(i);
                }
            }
            while (!s.empty())
                s.pop();
            for (int i = height.size() - 1; i >= 0; i--) {
                if (s.empty()) {
                    if (pse[i] == -1)
                        ans = max(ans, (int)(height[i] * height.size()));
                    else
                        ans = max(ans, (int)(height[i] * (height.size() - pse[i] - 1)));
                    s.push(i);
                }
                else {
                    while (!s.empty() && height[s.top()] >= height[i])
                        s.pop();
                    if (s.empty()) {
                        if (pse[i] == -1)
                            ans = max(ans, (int)(height[i] * height.size()));
                        else
                            ans = max(ans, (int)(height[i] * (height.size() - pse[i] - 1)));
                    }
                    else {
                        if (pse[i] == -1)
                            ans = max(ans, (int)(height[i] * s.top()));
                        else
                            ans = max(ans, (int)(height[i] * (s.top() - pse[i] - 1)));
                    }
                    s.push(i);
                }
            }
        }
        return ans;
    }
};