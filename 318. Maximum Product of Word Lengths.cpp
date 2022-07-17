// https://leetcode.com/problems/maximum-product-of-word-lengths/
// What I have done here is created a vector of map in which I am storing occurences of each character in a map of a particular word.
// Then I am checking for each word whether any letter is repeated in any two words or not, if not then I keep max val of 
// the length (i) * length(j)
// Time Complexity - O(n^2) Space Complexity - O(26*n)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<map<char, int>> freq(words.size());
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                freq[i][words[i][j]]++;
        
        int ans = 0;
        
        for (int i = 0; i < freq.size(); i++)
            for (int j = i + 1; j < freq.size(); j++) {
                bool common = false;
                for (auto k : freq[i])
                    if (freq[j].find(k.first) != freq[j].end()) {
                        common = true;
                        break;
                    }
                
                if (!common)
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
            }

        return ans;
    }
};


// Time Complexity theoritically same, but practically would be less due to bit manipulation, similarly space will also be less practically
// This bit manipulation approach hit me when i read the tag bit manipulation 😅
// What I have done here is that I can store every number in bits. i.e. if a is occuring i can represent it with 1
// if b is occuring i can represent it with 10, if c is occuring i can represent it with 100, similarly for all characters.
// Now if I do bitwise and between them and if no character is same then and will definitely be zero. Then I will calculate
// the max answer by multiplying indexes at that positions.
// Time Complexity - O(n^2) Space Complexity - O(n)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums(words.size());
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            vector<int> arr(26);
            for (int j = 0; j < words[i].size(); j++)
                arr[words[i][j] - 'a'] = 1;
            int num = 0;
            for (int j = 0; j < 26; j++) {
                if (arr[j])
                    num += 1 << j;
            }
            nums[i] = num;
            for (int j = 0; j < i; j++)
                if ((nums[i] & nums[j]) == 0)
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
        }
        return ans;
    }
};