// https://leetcode.com/problems/di-string-match/
// We can observe a simple pattern that for each I, we push from 0 to n
// and from each D we can push element from s.size to 0;
// Time Complexity - O(N), Space Complexity - O(N)
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans(s.size() + 1);
        int max = s.size(), min = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'I')
                ans[i] = min++;
            else
                ans[i] = max--;
        ans[s.size()] = max;
        return ans;
    }
};