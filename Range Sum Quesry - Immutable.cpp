// https://leetcode.com/problems/range-sum-query-immutable/
// A simple prefix sum problem
class NumArray {
public:
    vector<int> pref_sum;
    NumArray(vector<int>& nums) {
        pref_sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            pref_sum.push_back(nums[i] + pref_sum.back());
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return pref_sum[right];
        return pref_sum[right] - pref_sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */