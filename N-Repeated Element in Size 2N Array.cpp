// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Simply used hashmap, any element which gets repeated will be the element getting
// repeated n times.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            freq[nums[i]]++, freq[nums[j]]++;
            if (freq[nums[i]] > 1)
                return nums[i];
            else if (freq[nums[j]] > 1)
                return nums[j];
        }
        return -1;
    }
};