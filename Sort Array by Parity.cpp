// https://leetcode.com/problems/sort-array-by-parity/
// We have just swapped the elements if we encounter any even element with our 
// counter pointing to the next location of even elements getting end.
// It is basic two pointers approach.
// I have simply used in-place sorting here.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] % 2 == 0)
                swap(nums[i], nums[cnt++]);
        return nums;
    }
};

// Same we can do while creating a new array and traversing it two times, and
// firstly add all even to first position then all odd elements to next positions
// It is slower than above approach and also consumes space
// Time Complexity - O(N), Space Complexity - O(N)