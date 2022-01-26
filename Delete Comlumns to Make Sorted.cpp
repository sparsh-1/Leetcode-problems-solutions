// https://leetcode.com/problems/delete-columns-to-make-sorted/
// Just went over all the columns one by one and checked for each row if it is sorted or
// not, and counted the same.
// Time Complexity - O(n*m), Space Complexity - O(1)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        for (int i = 0; i < strs[0].size(); i++)
            for (int j = 1; j < strs.size(); j++)
                if (strs[j][i] < strs[j - 1][i]) {
                    cnt++;
                    break;
                }
        return cnt;
    }
};