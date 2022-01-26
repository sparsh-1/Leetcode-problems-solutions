// https://leetcode.com/problems/find-common-characters/
// I have utilised hashing, I am using a vector of 26 size representing 26 characters of
// english alphabet. And for each character I have further created a vector to store count of
// each alphabet in each word and minimum count will be taken for each character
// Time Complexity - O(n * words.size + 26*n*min_count), Space Complexity - O(n)
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> freq(26, vector<int>(words.size()));
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                freq[words[i][j] - 'a'][i]++;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < *min_element(freq[i].begin(), freq[i].end()); j++) {
                string s(1, 'a' + i);
                ans.push_back(s);
            }
        return ans;
    }
};