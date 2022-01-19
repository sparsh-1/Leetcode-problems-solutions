// https://leetcode.com/problems/assign-cookies
// Simple approach - First used sorting and then used two pointers to determine
// which child should get what cookie greedily.
// As a larger cookie can be assigned to more number of childs compared to 
// small sized cookie, we start with small sized cookie first
// Time Complexity - O(nlgn), Space Complexity - O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            while (j < s.size() && s[j] < g[i])
                j++;
            if (j < s.size() && s[j] >= g[i])
                ans++, i++, j++;
        }
        return ans;
    }
};