// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
// What I have done here is that I have first stored the small and capital letters present in the string
// After that from z to a I have checked whether a letter is present in both capital or not, if present I returned the 
// capital letter otherwise the empty string.
// Time Complexity - O(s.size()) Space Complexity - O(1)
class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> small(26, 0), large(26, 0);\
        for (auto i: s)
            if (i - 'a' >= 0)
                small[i - 'a'] = true;
            else
                large[i - 'A'] = true;
        for (int i = 25; i >= 0; i--)
            if (large[i] && small[i]) {
                return string(1, i + 'A');
            }
        return "";
    }
};