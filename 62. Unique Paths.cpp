// https://leetcode.com/problems/unique-paths/
// I have used recursion here, but only recursion is not sufficient, so I have used 
// map to store the previous state answer to speed up the process.
// Time Complexity - Space Complexity - O(n * m)
class Solution {
public:
    map<pair<int, int>, int> mp;
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        int a, b;
        if (mp.find(make_pair(m - 1, n)) != mp.end())
            a = mp[make_pair(m - 1, n)];
        else {
            a = uniquePaths(m - 1, n);
            mp[make_pair(m - 1, n)] = a;
        }
        if (mp.find(make_pair(m, n - 1)) != mp.end())
            b = mp[make_pair(m, n - 1)];
        else {
            b = uniquePaths(m, n - 1);
            mp[make_pair(m, n - 1)] = b;
        }
        return a + b;
    }
};

// More optimized approach
// I have used DP here, what each cell is representing that how can we reach that in how many ways
// we can reach that particular cell from starting if only that were the matrix.
// Time Complexity - O(m * n) Space Complexity - O(m * n)
class Solution {
public:
    map<pair<int, int>, int> mp;
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int>> grid(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        return grid[m - 1][n - 1];
    }
};

// Space optimized approach
// As I know, I only require the previous row for calculation and just the previous column
// so the previous column will be in the current row itself and I can keep previous row
// So, my space complexity got reduced.
// Time Complexity - O(m*n) Space Complexity - O(n)
class Solution {
public:
    map<pair<int, int>, int> mp;
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        vector<int> prev_row(n, 1), cur_row(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                cur_row[j] = cur_row[j - 1] + prev_row[j];
            swap(prev_row, cur_row);
        }
        return prev_row[n - 1];
    }
};

// Further reducing Time and Space Complexity
// This problem can be visualised as a combinatorial problem instead of the DP problem.
// We know for a m * n grid, a person has to move m - 1 + r - 1 steps down and right
// We just need to calculate total number of permutations.
// So, the answer will be (m + n)! / m! * n! - It is done so because of repeated elements
// repeats m and n times.
// Time Complexity - O(min(m, n)) Space Complexity - O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        m--, n--;
        if (m < n)
            swap(m, n);
        long res = 1;
        for (int i = m + 1, j = 1; i <= m + n; i++, j++) {
            res *= i;
            res /= j;
        }
        return res;
    }
};