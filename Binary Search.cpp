// https://leetcode.com/problems/binary-search/
// Just used Binary search to search for its lower bound
// Time Complexity - O(logn), Space Complexity - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto add = lower_bound(nums.begin(), nums.end(), target);
        if (add != nums.end() && *add == target)
            return add - nums.begin();
        return -1;
    }
};

// Second code
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (low < nums.size() && nums[low] == target)
            return low;
        return -1;
    }
};

// Third Code
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};