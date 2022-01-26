// https://leetcode.com/problems/smallest-range-i/
// If we can change all numbers then if largest numbers - k and smallest number + k
// ranges overlaps then it is possible to make all numbers equal thus max - min = 0,
// else difference between largest and smallest wil be largest - smallest - 2 * k;
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int large = 0, least = 1e4;
        for (auto i: nums) {
            if (i > large)
                large = i;
            if (i < least)
                least = i;
        }
        if (large - k <= least + k)
            return 0;
        else
            return large - 2 * k - least;
    }
};