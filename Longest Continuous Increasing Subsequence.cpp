// https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// I just have checked till when the array is increasing using two pointers.
// then, I update it in mx (i.e maximum length). We also need to update l and r accordingly.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() < 2)
            return 1;
        int l = 0, r = 1, mx = 1;
        while (r < nums.size()) {
            while (r < nums.size() && nums[r - 1] < nums[r])
                r++;
            mx = max(mx, r - l);
            l = r, r++;
        }
        return mx;
    }
};