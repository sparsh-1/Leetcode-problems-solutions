// https://leetcode.com/problems/maximum-product-of-three-numbers/
// I just have sorted the array,  now the maximum product can be (if there are negative numbers)
// smallest negative number product * largest postive number or product of three largest positive number. 
// Time Complexity - O(nlgn), Space Complexity - O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums.back(), nums.back() * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }
};

// We can also do the above question in linear times as we nee to compute 2 minimum and 3 maximum elements only.
// But the code will be lengthy thats why I am skippig it.