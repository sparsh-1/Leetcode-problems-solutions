// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int beg = 0, end = nums.size() - 1, mina = 5000;
        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (nums[beg] <= nums[end])
                return min(mina, nums[beg]);
            if (nums[mid] >= nums[beg]) {
                mina = min(mina, nums[beg]);
                beg = mid + 1;
            }
            else if (nums[mid] < nums[beg]) {
                mina = min(mina, nums[mid]);
                end = mid - 1;
            }
        }
        return mina;
    }
};