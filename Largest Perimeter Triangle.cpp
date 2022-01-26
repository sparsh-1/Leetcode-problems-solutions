// https://leetcode.com/problems/largest-perimeter-triangle/
// Sometimes I think myself a master to complicate simple things up, but without it
// how can we learn and grow. XD. 
// I have used a single iteration here while sorting, and am just checking different properties of
// triangles. But let me now demonstrate a much simpler and elegant second code.
// Time Complexity - O(nlgn), Space Complexity - O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = nums.size() - 1;
        while (i > 0) {
            int cntg = 1;
            while (i > 0 && nums[i] == nums[i - 1] && cntg < 3)
                i--, cntg++;
            if (cntg >= 3)
                return 3 * nums[i];
            else if (cntg >= 2)
                if (i > 0)
                    return 2 * nums[i] + nums[i - 1];
                else
                    return 0;
            else {
                if (i == 0)
                    return 0;
                int j = i - 1, cntm = 1;
                while (j > 0 && nums[j] == nums[j - 1] && cntm < 2)
                    j--, cntm++;
                if (cntm >= 2 && 2 * nums[j] > nums[i])
                    return 2 * nums[j] + nums[i];
                else 
                    if (j > 0 && nums[j] + nums[j - 1] > nums[i])
                        return nums[i] + nums[j] + nums[j - 1];
                    else
                        i--;
            }
        }
        return 0;
    }
};

// Second solution
// Time Complexity - O(nlgn), Space Complexity - O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--)
            if (nums[i] < nums[i - 1] + nums[i - 2])
                return nums[i] + nums[i - 1] + nums[i - 2];
        return 0;
    }
};