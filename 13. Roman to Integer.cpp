// https://leetcode.com/problems/roman-to-integer/
// I have started from end and moved to first and at any point of time if I encounter any small value before the large one
// I will decrease the value from answer otherwise I will increase.
// Time Complexity - O(s.size()), Space Complexity - O(1) [we can ignore log n facto and space as map is really small]
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> a {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = a[s.back()];
        for (int i = s.size() - 2; i >= 0; i--) {
            if (a[s[i]] < a[s[i + 1]])
                ans -= a[s[i]];
            else
                ans += a[s[i]];
        }
        return ans;
    }
};

// Just the reverse approach
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = mp[s[0]];
        for (int i = 1; i < s.size(); i++)
            if (mp[s[i]] <= mp[s[i - 1]])
                ans += mp[s[i]];
            else
                ans += mp[s[i]] - 2 * mp[s[i - 1]];
        return ans;
    }
};