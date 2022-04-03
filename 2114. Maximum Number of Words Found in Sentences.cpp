// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
// As it is mentioned here that there are not more than 1 spaces between words and there is atleast 1 word in the sentence
// so as soon as a space is encountered we will increase the word count.
// Time Complexity - O(n), Space Complexity -O(1)
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int word = 0;
        for (int i = 0; i < sentences.size(); i++) {
            int j = 0, tword = 0;
            for (; j < sentences[i].size(); j++)
                if (sentences[i][j] == ' ')
                    tword++;
            tword++;
            word = max(word, tword);
        }
        return word;
    }
};