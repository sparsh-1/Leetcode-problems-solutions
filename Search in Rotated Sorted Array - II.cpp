// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
/* In this approach I jut simply applied linear search because in my worst case and average case it took O(n) time complexity
   But we can also implement the binary search like that we have implemented in the search in sorted array - I, but there is a difficulty
   Lets first and last elements are equal then we have to increment the first pointer to first + 1 as we will not be able to figure out
   that our target is lying in which part(i.e left or right)
*/
class Solution {
public:
    bool search(vector<int>& arr, int target) {
        if (count(arr.begin(), arr.end(), target) > 0)
            return true;
        else
            return false;
    }
};