// https://leetcode.com/problems/verifying-an-alien-dictionary/
// I have created a hashing from unordered map, and compared every character, if at any point it is
// smaller than the next character then those two words are in sorted manner.
// This rule will break when opposite occurs.
// Time Complexity - O(word.size * max(word[i].size)), Space Complexity - O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& word, string order) {
        unordered_map<char, int> lexord;
        for (int i = 0; i < 26; i++)
            lexord[order[i]] = i;
        for (int i = 0; i < word.size() - 1; i++) {
            int j = 0;
            for (; j < min(word[i].size(), word[i + 1].size()); j++)
                if (lexord[word[i][j]] < lexord[word[i + 1][j]])
                    break;
                else if (lexord[word[i][j]] > lexord[word[i + 1][j]])
                    return false;
            if (j == min(word[i].size(), word[i + 1].size()) && word[i].size() > word[i + 1].size())
                return false;
        }
        return true;
    }
};