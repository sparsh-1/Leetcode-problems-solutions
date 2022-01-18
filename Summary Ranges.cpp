// https://leetcode.com/problems/summary-ranges/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0)
            return ans;
        int start = nums[0], i = 1, end = nums[0];
        while (i < nums.size()) {
            if (nums[i] - 1 == nums[i - 1]) {
                end = nums[i++];
                continue;
            }
            if (start == end)
                ans.push_back(to_string(start));
            else
                ans.push_back(to_string(start) + "->" + to_string(end));
            start = end = nums[i++];
        }
        if (start == end)
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start) + "->" + to_string(end));
        return ans;
    }
};