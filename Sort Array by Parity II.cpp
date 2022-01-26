// https://leetcode.com/problems/sort-array-by-parity-ii/
// I have done in place sorting using two pointers. Just swapped odd and even
// elements till odd or even will reach at end i.e whole odd or even are
// placed at their correct positions.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& arr) {
        int ev = 0, od = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (max(ev, od) >= arr.size())
                break;
            if (i % 2 == 0 && arr[i] % 2 == 0 && i >= ev)
                ev += 2;
            else if (i % 2 == 1 && arr[i] % 2 == 1 && i >= od)
                od += 2;
            else if (i % 2 == 0 && arr[i] % 2 == 1) {
                while (od < arr.size() && arr[od] % 2 == 1)
                    od += 2;
                swap(arr[od], arr[i]);
                od += 2;
                ev += 2;
            }
            else if (i % 2 == 1 && arr[i] % 2 == 0) {
                while (ev < arr.size() && arr[ev] % 2 == 0)
                    ev += 2;
                swap(arr[ev], arr[i]);
                ev += 2;
                od += 2;
            }
        }
        return arr;
    }
};