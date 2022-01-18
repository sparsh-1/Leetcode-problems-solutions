// https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> firstlast;
        for (int i = 0; i < nums.size(); i++) {
            if (firstlast.find(nums[i]) == firstlast.end())
                firstlast[nums[i]] = i;
            else {
                if (i - firstlast[nums[i]] <= k)
                    return true;
                firstlast[nums[i]] = i;
            }
        }
        return false;
    }
};