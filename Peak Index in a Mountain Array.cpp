// https://leetcode.com/problems/peak-index-in-a-mountain-array/
// The point where the element is greater than its prefix max and suffix max 
// will be the answer, so we return its index, but we need 2 passes and space
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int> pre_max(arr.size(), arr[0]), suf_max(arr.size(), arr.back());
        for (int i = 1; i < arr.size(); i++)
            pre_max[i] = max(arr[i], pre_max[i - 1]);
        for (int i = arr.size() - 2; i >= 0; i--) {
            suf_max[i] = max(arr[i], suf_max[i + 1]);
            if (arr[i] >= pre_max[i] && arr[i] >= suf_max[i])
                return i;
        }
        return -1;
    }
};

// On a second thought we only need the max element index as it will be greater 
// than both its left and right
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max_ind = 0;
        for (int i = 1; i < arr.size(); i++)
            max_ind = arr[max_ind] > arr[i] ? max_ind : i;
        return max_ind;
    }
};

// We can also see that the function is something like unimodal function
// i.e It first strictly increases and reach a max and then strictly decreases
// or vice versa. Here we can do two things either binary search or a ternary search
// In binary search we will compare it with mid - 1 and mid + 1, in ternary search
// we can see if the mid point is greater between the left and right then the 
// maxima or minima occurs in between of those left and right point, if mid point 
// is greater than left but less than right then we know that the answer lies 
// between right point and the rightmost point. Same it is for left case.
// Time Complexity - O(logn), Space Complexity - O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1])
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};