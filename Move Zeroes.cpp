// https://leetcode.com/problems/move-zeroes/
// Simply moved non-zero elements at beginnning(inplace), but if still count 
// not reached nums.length then those elements are zeroes, so populated
// the remaining array with zeroes.
// Time complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                nums[cnt++] = nums[i];
        for (int i = cnt; i < nums.size(); i++)
            nums[i] = 0;
    }
};