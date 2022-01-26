// https://leetcode.com/problems/shortest-distance-to-a-character/
// I have stored the indexes where character c is occuring an then compared each
// character with correct position of indexes.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> indocc, ans;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == c)
                indocc.push_back(i);
        int place = 0;
        for (int i = 0; i < s.size(); i++) {
            if (place == 0)
                ans.push_back(abs(i - indocc[place]));
            else if (place > 0)
                ans.push_back(min(abs(i - indocc[place]), abs(i - indocc[place - 1])));
            if (i == indocc[place] && place + 1 < indocc.size())
                place++;
        }
        return ans;
    }
};