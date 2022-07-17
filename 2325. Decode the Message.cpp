// https://leetcode.com/problems/decode-the-message/
// I just have created a mapping of characters first occuring with the english alphabets. Then I iterated on message
// and then appended in answer accordingly.
// Time Complexity - O(max(len(key), len(message))), Space Complexity - O(26)
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mapping;
        int a = 0;
        for (int i = 0; i < key.size(); i++) {
            if (key[i] != ' ' && mapping.find(key[i]) == mapping.end())
                mapping[key[i]] = (char)(a++ + 'a');
            else if (a > 25)
                break;
        }
        string ans = "";
        for (int i = 0; i < message.size(); i++) {
            if (message[i] == ' ')
                ans += ' ';
            else
                ans += mapping[message[i]];
        }
        return ans;
    }
};