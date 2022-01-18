// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int beg = 0, end = arr.size() - 1;
        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target) {
                if (arr[mid] > arr[beg]) {
                    beg = mid + 1;
                }
                else {
                    if (target <= arr[end])
                        beg = mid + 1;
                    else
                        end = mid - 1;
                }
            }
            else {
                if (arr[mid] > arr[beg]) {
                    if (target >= arr[beg])
                        end = mid - 1;
                    else
                        beg = mid + 1;
                }
                else if (arr[beg] == target)
                    return beg;
                else if (arr[end] == target)
                    return end;
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};