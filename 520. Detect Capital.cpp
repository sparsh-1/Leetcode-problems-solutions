// https://leetcode.com/problems/detect-capital/
// Just checked if first two letters are capital then whole string should be capital.
// If first character is capital then all characters need to be smallcase.
// If second letter is capital then condition fails
// If both first and second are small then whole string needs to be small
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1)
            return true;
        bool first = ((word[0] - 'A') <= 26);
        bool second = ((word[1] - 'A') <= 26);
        if (first && second) {
            for (int i = 2; i < word.size(); i++)
                if ((word[i] - 'A') > 26)
                    return false;
            return true;
        }
        if (second)
            return false;
        if (first) {
            for (int i = 2; i < word.size(); i++)
                if (word[i] - 'A' <= 26)
                    return false;
            return true;
        }
        for (int i = 2; i < word.size(); i++)
            if (word[i] - 'A' <= 26)
                return false;
        return true;
    }
};