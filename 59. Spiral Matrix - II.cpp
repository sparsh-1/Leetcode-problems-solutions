// https://leetcode.com/problems/spiral-matrix-ii/
// I haven't done any extraordinary thing here, just traversed layer by layer, my layers are like boundaries
// of the matrix. I am incrementing the counter and storing values at different positions.
// Time Complexity - O(n2), Space Complexity - O(n2)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1)
            return {{1}};
        else if (n == 2)
            return {{1, 2}, {4, 3}};
        vector<vector<int>> matrix(n, vector<int>(n));
        int sti = 0, stj = 0, eni = n - 1, enj = n - 1, cnt = 1;
        while (stj < enj) {
            int j = stj;
            while (j != enj + 1)
                matrix[sti][j++] = cnt++;
            sti++;
            int i = sti;
            while (i != eni + 1)
                matrix[i++][enj] = cnt++;
            enj--;
            j = enj;
            while (j != stj - 1)
                matrix[eni][j--] = cnt++;
            eni--;
            i = eni;
            while (i != sti - 1)
                matrix[i--][stj] = cnt++;
            stj++;
        }
        if (n % 2 == 0)
            return matrix;
        matrix[n/2][n/2] = cnt;
        return matrix;
    }
};