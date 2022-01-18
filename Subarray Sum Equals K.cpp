// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, cur_sum = 0;
        unordered_map<int, int> previous_sum;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            if (cur_sum == k)
                ans++;
            ans += previous_sum[cur_sum - k];
            previous_sum[cur_sum] += 1;
        }
        return ans;
    }
};
