// https://leetcode.com/problems/kth-largest-element-in-an-array/
// What I have done here is just sorted the whole array and returned the kth element from the last.
// Time Complexity - O(nlgn) Space Complexity - O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// Here, I have used the concept of quick sort (or divide and conquer), Here I will sort only that part of array which is
// required to be sorted using divide and conquer technique.
// Time Complexity - O(nlgn), Space Complexity - O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        k = nums.size() - k;
        while (start <= end) {
            int pivot = nums[start], inds = start, inde = end;
            int i = start + 1;
            while (inds < inde) {
                if (nums[i] > pivot)
                    swap(nums[i], nums[inde--]);
                else
                    nums[inds++] = nums[i++];
            }
            if (inds < k)
                start = inds + 1;
            else
                end = inds - 1;
            nums[inds] = pivot;
        }
        return nums[start];
    }
};

// Instead of taking pivot as first or the last element, we can take it as a random pivot within our specified range
// It will make our algorithm work in approximately O(n) time
// Time Complexity - O(n) (most of the time) Space complexity - O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        k = nums.size() - k;
        while (start <= end) {
            srand(time(0));
            int pind = start + rand() % (end - start + 1);
            int pivot = nums[pind], inds = start, inde = end;
            swap(nums[start], nums[pind]);
            int i = start + 1;
            while (inds < inde) {
                if (nums[i] > pivot)
                    swap(nums[i], nums[inde--]);
                else
                    nums[inds++] = nums[i++];
            }
            if (inds < k)
                start = inds + 1;
            else
                end = inds - 1;
            nums[inds] = pivot;
        }
        return nums[start];
    }
};