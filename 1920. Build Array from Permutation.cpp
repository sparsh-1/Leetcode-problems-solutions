// https://leetcode.com/problems/build-array-from-permutation/
// I just have created a new array and copied the old array elements as told. But we can even do it without
// utilising extra space
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
            ans[i] = nums[nums[i]];
        return ans;
    }
}