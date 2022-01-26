// https://leetcode.com/problems/valid-mountain-array/
// I have traversed till the max of the array and then traversed to end if the condition
// fullfills. In between I also checked that isn't the array only increasing or decreasing.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        int i = 1;
        for (; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1])
                continue;
            else if (arr[i] == arr[i - 1])
                return false;
            else 
                break;
        }
        if (i == arr.size() || ((i == 1) && (arr[i] < arr[i - 1])))
            return false;
        for (; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1])
                continue;
            else
                return false;
        }
        return true;
    }
};