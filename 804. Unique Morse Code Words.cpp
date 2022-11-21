// https://leetcode.com/problems/unique-morse-code-words/
// I just have created morse code for every string inside words and then appended it to te set
// The size of the set will be our answer. We even can use map, unorderd_map, etc
// Time Complexity - O(n*logn) [If we assume complexity of set to be log n] Space Complexity - O(n)
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> ans;
        for (int i = 0; i < words.size(); i++) {
            string temp = "";
            for (int j = 0; j < words[i].size(); j++)
                temp += morse[words[i][j] - 'a'];
            ans.insert(temp);
        }
        return ans.size();
    }
};