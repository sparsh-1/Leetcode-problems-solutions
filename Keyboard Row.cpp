// https://leetcode.com/problems/keyboard-row/
// I have used simple hashing to pair a keyboard line to a particular number
// If all values of words are same then it can be constructed from a single
// keyboard line otherwise not.
// Time Complexity - O(n*word[i].size), Space Complexity - O(1)
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<int> arr{1, 3, 3, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3, 3, 2, 2, 2, 2, 1, 2, 2, 3, 2, 3, 2, 3};
        for (int i = 0; i < words.size(); i++) {
            bool flag = true;
            for (int j = 1; j < words[i].size(); j++)
                if (arr[tolower(words[i][j]) - 'a'] != arr[tolower(words[i][j - 1]) - 'a']) {
                    flag = false;
                    break;
                }
            if (flag)
                ans.push_back(words[i]);
        }
        return ans;
    }
};