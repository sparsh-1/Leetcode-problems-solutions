// https://leetcode.com/problems/maximum-product-subarray/
// Here, I have used two variables current maximum and current minimum whichwill be storing the current maximum and minimum
// value (i.e. product) and if I encounter 0 I will reset the condition.
// Time Complexity - O(n) Space Complexity - O(1)
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