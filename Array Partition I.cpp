// https://leetcode.com/problems/array-partition-i/
// Here we know that pairing a big number with a much smaller will decrease the big number
// chance of getting in, so the best wy to tackle is to pair adjacent pairs 
// in sorted array which will help maximise the answer
// Time Complexity - O(nlgn), Space Complexity - O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2)
            ans += nums[i];
        return ans;
    }
};