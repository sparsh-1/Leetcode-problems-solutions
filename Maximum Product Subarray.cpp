// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int cma = 1, cmi = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cma = 1;
                cmi = 1;
            }
            int temp = nums[i] * cma;
            cma = max(nums[i] * cma, max(nums[i] * cmi, nums[i]));
            cmi = min(temp, min(nums[i] * cmi, nums[i]));
            res = max(cma, res);
        }
        return res;
    }
};