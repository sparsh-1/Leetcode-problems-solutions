// https://leetcode.com/problems/monotonic-array/
// Just checked if the array is increasing or decreasing.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        if (nums[0] <= nums.back()) {
            for (int i = 1; i < nums.size(); i++)
                if (nums[i] < nums[i - 1])
                    return false;
            return true;
        }
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > nums[i - 1])
                return false;
        return true;
    }
};