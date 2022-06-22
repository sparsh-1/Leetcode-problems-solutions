// https://leetcode.com/problems/find-k-closest-elements/
// I have first checked 3 conditions 
// 1. If k == arr.size() i.e. all elements should be included no matter whatever x should be
// 2. If x <= arr[0] i.e. All the elements should be taken from start only
// 3. If x >= arr.back() i.e. All the elements should be taken from last only
// After that I have find the position of x in the array using binary search and included the closest element in my list
// I have taken two pointers one before and one after, which will denote the elements which are currently not in the 
// ans array i.e. everything between them (excluding before and after) are part of ans.
// I have just handled the out of bound errors as before should be ahead or equal to 0 and after shd be behind end.
// Time Complexity - O(n) (Can alsoe be written as (log(n) + k)) Space Complexity - O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == arr.size())
            return arr;
        if (x <= arr[0])
            return {arr.begin(), arr.begin() + k};
        if (x >= arr.back())
            return {arr.begin() + arr.size() - k, arr.end()};
        int start = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (start > 0 && x - arr[start - 1] <= arr[start] - x)
            start--;
        int before = start - 1, after = start + 1;
        while (after < arr.size() && before >= 0 && after - before <= k) {
            if (x - arr[before] <= arr[after] - x)
                before--;
            else
                after++;
        }
        if (before >= 0 && after - before - 1 == k)
            return {arr.begin() + before + 1, arr.begin() + after};
        else if (before < 0)
            return {arr.begin(), arr.begin() + k};
        return {arr.begin() + arr.size() - k, arr.end()};
    }
};


// ✔️ Solution - IV (Optimized Binary-Search and 2-Pointers)
// We can see that the answer would always be an array of k elements. So, the left pointer L must always start atleast k positions from the end, otherwise we would not have enough elements for our answer. So, instead of doing binary search on the entire arr, we could just do a binary search on [0, n-k] indices of arr.
// Here, R won't always hold the index of smallest elmeent >= x as it did above but rather it holds index of some element that we are sure would be part of the final window. Thereafter, the process will remain the same of above - use 2-pointers to fit k elements inside our window.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), R = lower_bound(begin(arr), end(arr) - k, x) - begin(arr), L = R - 1;
        while(k--) 
            if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;
            else R++;
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};
// Time Complexity : O(log(n-k) + k), We need O(logn) time complexity to find r at the start. Then we need another O(k) time to expand our window to fit k elements
// Space Complexity : O(1)