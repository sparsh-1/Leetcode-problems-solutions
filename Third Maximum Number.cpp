// https://leetcode.com/problems/third-maximum-number/
// Here in first case I have checked if the first and last numbers are equal it means
// that onle one element is present in the array,  then if lower bound of element occuring
// just before the last element is equal to first one then there are only two numbers present.
// If both these fails then atleast three numbers are present.
// So I simply applied binary search to check for the third element.
// Time Complexity - O(nlgn), Space complexity - O(1)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int largest_ind = lower_bound(nums.begin(), nums.end(), nums.back()) - nums.begin() - 1;
        if (nums[0] == nums.back() || nums[largest_ind] == nums[0])
            return nums.back();
        return nums[lower_bound(nums.begin(), nums.begin() + largest_ind, nums[largest_ind]) - nums.begin() - 1];
    }
};

// Another approach is to maintain three numbers i.e first largest, second largest
// and third largest, and give output accordingly
// Time Complexity - O(n), Space Complexity - O(1)
