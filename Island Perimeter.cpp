// https://leetcode.com/problems/island-perimeter/
// I have hardcoded the solution to get to the result and can't think of a better way
// Time Complexity - O(6*m*n), Space Complexity - O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 && j == 0 && grid[i][j] == 1) {
                    peri += 2;
                    if (i + 1 < grid.size() && grid[i + 1][j] == 0)
                        peri++;
                    if (i + 1 == grid.size())
                        peri++;
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == 0)
                        peri++;
                    if (j + 1 == grid[i].size())
                        peri++;
                }
                else if (i == 0 && grid[i][j] == 1) {
                    peri++;
                    if (grid[i][j - 1] == 0)
                        peri++;
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == 0)
                        peri++;
                    if (j + 1 == grid[i].size())
                        peri++;
                    if (i + 1 < grid.size() && grid[i + 1][j] == 0)
                        peri++;
                    if (i + 1 == grid.size())
                        peri++;
                }
                else if (j == 0 && grid[i][j] == 1) {
                    peri++;
                    if (grid[i - 1][j] == 0)
                        peri++;
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == 0)
                        peri++;
                    if (j + 1 == grid[i].size())
                        peri++;
                    if (i + 1 < grid.size() && grid[i + 1][j] == 0)
                        peri++;
                    if (i + 1 == grid.size())
                        peri++;
                }
                else if (grid[i][j] == 1) {
                    if (grid[i - 1][j] == 0)
                        peri++;
                    if (grid[i][j - 1] == 0)
                        peri++;
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == 0)
                        peri++;
                    if (j + 1 == grid[i].size())
                        peri++;
                    if (i + 1 < grid.size() && grid[i + 1][j] == 0)
                        peri++;
                    if (i + 1 == grid.size())
                        peri++;
                }
                cout << peri << "\n";
            }
        return peri;
    }
};

// Saw this solution in which for each cell we are adding +4 and if we have a top or
// left sheell as island then we remove -2, it is not much faster than above
// but it is really small and a nice approach
// Time Complexity - O(m*n), Space Complexity - O(1)
int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0; j<grid[i].size();j++)
                if(grid[i][j]==1) {
                    count ++;
                    if(i!=0 && grid[i-1][j] == 1) repeat++;
                    if(j!=0 && grid[i][j-1] == 1) repeat++;
                }
        return 4 * count - repeat * 2;
    }