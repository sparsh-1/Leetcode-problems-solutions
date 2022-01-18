// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Same we can do it with binary search solution discussed in rotated sorted array - II, which will take O(n) worst time.
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};
/* Binary search solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while (l < r) {
            if (nums[l] < nums[r]) { return nums[l]; }
            
            int mid = l+(r-l)/2;
            if (nums[l] > nums[mid]) {
                r = mid;
            } else if (nums[l] < nums[mid]) {
                l = mid+1;
            } else {
                ++l;
            }
        }
        return nums[l];               
    }
};
*/