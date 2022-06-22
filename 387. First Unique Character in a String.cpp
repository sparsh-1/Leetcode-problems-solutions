// https://leetcode.com/problems/first-unique-character-in-a-string/
// What I have done here is I have created a map in which I am storing the frequencies of each element and along with
// it I am storing the first occurence of a character in an array. Then traversing the array I am chacking whether 
// the element occured only once, if yes I returned that index, otherwise I return -1.
// Time Complexity - (s.size()*log(s.size())) Space Complexity - O(1) {As only 26 letters are there so only O(26 space is reqd.)}
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> oc;
        vector<char> c;
        vector<int> ind;
        for (int i = 0; i < s.size(); i++) {
            oc[s[i]]++;
            if (find(c.begin(), c.end(), s[i]) == c.end())
                c.push_back(s[i]), ind.push_back(i);
        }
        for (int i = 0; i < c.size(); i++)
            if (oc[c[i]] == 1)
                return ind[i];
        return -1;
    }
};

// A little optimized version of the code
// Here I have removed the vector as I can reiterate on the array to check whether frequency of an element is 1 or not.
// Time Complexity - O(s.size()*log(s.size())) Space Complexity - O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> oc;
        for (int i = 0; i < s.size(); i++) {
            oc[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
            if (oc[s[i]] == 1)
                return i;
        return -1;
    }
};

// Used unordered map this time removing log (s.size()) factor too.
// Time Complexity - O(s.size()) Space Complexity - O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> oc;
        for (int i = 0; i < s.size(); i++) {
            oc[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
            if (oc[s[i]] == 1)
                return i;
        return -1;
    }
};

// Used hashing from array, so reduced the average O(1) of unordered map to exact O(1)
// Time Complexity - O(s.size()) Space Complexity - O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26, 0);
        for (int i = 0; i < s.size(); i++)
            arr[s[i] - 'a']++;
        for (int i = 0; i < s.size(); i++)
            if (arr[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};