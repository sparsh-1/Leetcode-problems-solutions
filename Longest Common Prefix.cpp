// https://leetcode.com/problems/longest-common-prefix/
// I have used vertical scanning approach, just checked till where the starting positions are same.
// As soon as i found an unequal value, till previous index was my answer.
// Time Complexity - O(sum of all strings), Space Complexity - O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs.back();
        int sz = 0, i = 0;
        for (; i < strs[0].size(); i++)
            for (int j = 1; j < strs.size(); j++) {
                if (i > strs[j].size() || strs[j][i] != strs[j - 1][i])
                    return strs[0].substr(0, i);
            }
        if (i == strs[0].size())
            return strs[0];
        return "";
    }
};