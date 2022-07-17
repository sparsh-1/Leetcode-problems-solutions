// https://leetcode.com/problems/maximal-square/
// I have used Largest area in a histogram approach here. But the only thing which I changed here is that instead
// of finding rectangle we have to find square. So for that purpose I have taken the minimum(length, width) of rectangle
// and just squared it as it will the max area of square residing inside a rectangle.
// Time Complexity - O(m*n) Space Complexity - O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> height(matrix[0].size());
        int ans = 0, temp = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                height[j] = matrix[i][j] =='1' ? height[j] + 1 : 0;
            stack <int> s;
            vector<int> psmall(matrix[0].size());
            for (int i = 0; i < height.size(); i++) {
                if (s.empty())
                    psmall[i] = -1;
                else if (height[s.top()] < height[i])
                    psmall[i] = s.top();
                else {
                    while (!s.empty() && height[s.top()] >= height[i])
                        s.pop();
                    if (s.empty())
                        psmall[i] = -1;
                    else
                        psmall[i] = s.top();
                }
                s.push(i);
            }
            while (!s.empty())
                s.pop();
            for (int i = height.size() - 1; i >= 0; i--) {
                if (s.empty()) {
                    if (psmall[i] == -1)
                        temp = min((int)height.size(), height[i]);
                    else
                        temp = min(height[i], (int)height.size() - psmall[i] - 1);
                }
                else if (height[s.top()] < height[i]) {
                    if (psmall[i] == -1)
                        temp = min(s.top(), height[i]);
                    else
                        temp = min(height[i], s.top() - psmall[i] - 1);
                }
                else {
                    while (!s.empty() && height[i] <= height[s.top()])
                        s.pop();
                    if (s.empty()) {
                        if (psmall[i] == -1)
                            temp = min((int)height.size(), height[i]);
                        else
                            temp = min(height[i], (int)height.size() - psmall[i] - 1);
                    }
                    else {
                        if (psmall[i] == -1)
                            temp = min(s.top(), height[i]);
                        else
                            temp = min(height[i], s.top() - psmall[i] - 1);
                    }
                }
                ans = max(ans, temp * temp);
                s.push(i);
            }
        }
        return ans;
    }
};


// DP Approach
// In the DP approach we can even take the whole matrix making space complexity to O(mn), but as we are required only the previous row
// and the current row, we can reduce it to O(n).
// Now, if we found any 1 we know that it will definite make a square of area 1. Now we can check (i, j - 1), 
// (i - 1, j - 1), (i - 1, j). If any of these is 0 then a square of area greater than 1 is not possible, but if we found all these previous
// as 1s then we know for sure that we can build a square with area of 4, similarly we can replicate the whole process in the 
// matrix, if we find (i, j - 1), (i - 1, j - 1), (i - 1, j) as as 2 this means that (i, j - 1) have a square with area 2, 
// (i - 1, j - 1) have a square with area 2, (i - 1, j) have a square with area 2, so if this tile i.e. (i, j) is 1 together they will
// definite make a square with area 9.
// Time Complexity - O(mn), Space Complexity - O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size() + 1);
        int ans = 0, temp = 0;
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                int prev = dp[j];
                if (matrix[i - 1][j - 1] == '0')
                    dp[j] = 0;
                else {
                    dp[j] = min(dp[j - 1], min(dp[j], temp)) + 1;
                    if (dp[j] > ans)
                        ans = dp[j];
                }
                temp = prev;
            }
        }
        return ans * ans;
    }
};