// https://leetcode.com/problems/rotate-array/
// What I have done here is that if nums.size is a multiple of k, then we know that the array will become the
// same array again. If I encounter some other number than k, then I know that array rotation follows a 
// specific pattern, i.e 1 % nums.size == (nums.size + 1) % nums.size == (nums.size * 2 + 1) % nums.size == ...
/// So I have copied the last ke elements of the array, then exchanged remaining first with last
// and then again copied the first elements from the change array.
// Time Complexity - O(n or nums.size), Space Complexity - O(k)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0 || k % nums.size() == 0)
            return;
        if (k > nums.size())
            k = k % nums.size();
        vector<int> change(k);
        for (int i = nums.size() - k; i < nums.size(); i++)
            change[i - nums.size() + k] = nums[i];
        for (int i = nums.size() - k - 1; i >= 0; i--)
            nums[i + k] = nums[i];
        for (int i = 0; i < change.size(); i++)
            nums[i] = change[i];
        return;
    }
};

