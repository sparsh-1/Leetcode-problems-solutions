// https://leetcode.com/problems/ransom-note/
// Just applied simple mapping approach and check whether all letters of ransom can be taken from magazine or not
// Time Complexity - O(max(ransom, magazine)) Space Complexity - O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr1(26), arr2(26);
        for (auto i: ransomNote)
            arr1[i - 'a']++;
        for (auto i: magazine)
            arr2[i - 'a']++;
        for (int i = 0; i < 26; i++)
            if (arr1[i] > arr2[i])
                return false;
        return true;
    }
};