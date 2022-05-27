// https://leetcode.com/problems/kth-missing-positive-number/
// As we always have to start the series from 1, and the sequence is always increasing, we can easily use binary 
// search here. I simply comared total elements with its length, the difference bwtween them is the missing numbers
// or we can say hidden numbers.
// PS - I have written these +1 - 1 = 0, purposefully for your ability to understand easily. i.e mid element - first 
// element + 1 for taking out the length. ;)
// Time Complexity - O(logn), Space Complexity - O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr.back() - 1 + 1 == arr.size())
            return arr.back() + k;
        else if (arr[0] > k)
            return k;
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] - 1 + 1 - (mid + 1) >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return arr[high] + k - (arr[high] - 1 + 1 - (high + 1));
    }
};