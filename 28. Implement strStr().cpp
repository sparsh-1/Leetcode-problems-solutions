// https://leetcode.com/problems/implement-strstr/
// I have used normal STL function here (find), it will return the position of first occurence
// of substring inside the string. If it can't find it in string it will return npos.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        auto f = haystack.find(needle);
        if (f != string::npos)
            return f;
        return -1;
    }
};

// Brute force Approach
// For every character we will compare in both strings. If length came out to be equal, ew return true
// otherwise false
// Time Complexity - O(n2), Space Complexity - O(1)
class Solution {
public:    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            int j = i;
            for (; j < needle.size() + i; j++) {
                if (haystack[j] != needle[j - i])
                    break;
            }
            if (j - i == needle.size())
                return i;
        }
        return -1;
    }
};


// KMP (Knuth Morris Pratt) Algorithm