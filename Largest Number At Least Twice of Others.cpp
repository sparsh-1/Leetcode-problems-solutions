// https://leetcode.com/problems/largest-number-at-least-twice-of-others/
// I have checked for every number that its twice should be less than or equal to the
// largest number except for 1 time when the number occurs itself. If this happens
// more than 1 time then condition becomes false.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto max_ind = max_element(nums.begin(), nums.end());
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] * 2 > *max_ind)
                cnt--;
            if (cnt < 0)
                return -1;
        }
        return max_ind - nums.begin();
    }
};