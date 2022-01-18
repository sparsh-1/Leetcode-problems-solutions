// https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftsum, rightsum;
        leftsum.push_back(0);
        for(int i = 1; i < nums.size(); i++)
            leftsum.push_back(leftsum.back() + nums[i - 1]);
        rightsum.push_back(leftsum.back() + nums[nums.size() - 1] - nums[0]);
        for (int i = 1; i < nums.size(); i++)
            rightsum.push_back(rightsum.back() - nums[i]);
        for (int i = 0; i < nums.size(); i++)
            if (leftsum[i] == rightsum[i])
                return i;
        return -1;
    }
};

// Much more efficient solution (both in O(n) time complexity but second one requires no space and is traversing the array only once)
class Solution(object):
    def pivotIndex(self, nums):
        S = sum(nums)
        leftsum = 0
        for i, x in enumerate(nums):
            if leftsum == (S - leftsum - x):
                return i
            leftsum += x
        return -1