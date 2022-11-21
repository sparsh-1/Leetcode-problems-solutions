// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// As the constraints are very small I entered every element in the array and sorted the array, and just returned
// the kth smallest elements.
// Time Complexity - O(n^2) Space Complexity - O(n^2)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix.size(); j++)
                arr.push_back(matrix[i][j]);
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }
};

// Second Approach
