// https://leetcode.com/problems/longest-harmonious-subsequence/
// Used map property as it stores in a sorted manner and then checked if difference
// between adjacent number is 1, if it is then add it to the answer.
// Same it can be solved with unordered map too which have average
// time coplexity of O(n)
// Time Complexity - O(nlgn), Space complexity - O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        int ans = 0, prev = freq.begin()->first;
        for (auto it : freq) {
            if (it.first - prev == 1)
                ans = max(ans, it.second + freq[prev]);
            prev = it.first;
        }
        return ans;
    }
};