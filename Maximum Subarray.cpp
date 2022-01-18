// https://leetcode.com/problems/maximum-subarray/
// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > 0)
                nums[i] += nums[i - 1];
            sum = max(sum, nums[i]);
        }
        return sum;
    }
};