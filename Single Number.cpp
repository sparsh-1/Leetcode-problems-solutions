// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
            nums[i] ^= nums[i - 1];
        return nums[nums.size() - 1];
    }
};