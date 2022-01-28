// https://leetcode.com/problems/range-addition-ii/
// We know that the first cell is always the maximum element 
// i.e we know that it will always get included. So ew find smallest area among all pairs.
// the smallest area will always get incremented, and thus will be our answer.
// Time Complexity - O(ops.size), Space Complexity - O(1)
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m * n;
        int min_a = 4e4, min_b = 4e4;
        for (auto i: ops) {
            min_a = min(i[0], min_a);
            min_b = min(i[1], min_b);
        }
        return min_a * min_b;
    }
};