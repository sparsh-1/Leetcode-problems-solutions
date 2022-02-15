// https://leetcode.com/problems/length-of-last-word/
// First I removed redundant spaces frm the last (if any), then I calculated length
// till I encounter a space or I reached the finish point.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, cnt = 0;
        while (s[i] == ' ')
            i--;
        while (i >= 0 && s[i] != ' ')
            cnt++, i--;
        return cnt;
    }
};