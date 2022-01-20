// https://leetcode.com/problems/merge-intervals/
// I simply just sorted the array and then checked if start time of next interval is less 
// than end time of previous interval i.e these intervals overlap. 
// I even have to check for one more case that a particular interval can even lie
// full inside previous interval so we don't have to check for the end time.
// Time Complexity - O(nlgn), Space Complexity - O(n) or O(1)[excluding return vector]
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
            if (intervals[i][0] <= ans.back()[1])
                if (intervals[i][1] <= ans.back()[1])
                    continue;
                else
                    ans.back()[1] = intervals[i][1];
            else
                ans.push_back(intervals[i]);
        return ans;
    }
};