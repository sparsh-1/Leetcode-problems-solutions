// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Unfortunate to say that this code which I have written is not working for the last testcase.
// It is giving TLE for last test case. Now, before I wrote this code I am not familiar with the concept
// of tries. But after seeing TLE for various times I came to tries. What I have done is actually the same 
// thing as tries. But I have hardcoded the problem. Binary tries can solve the problem in logn complexity
// As we know XOR will become maximum is and only if the bit will get correspond to its opposite bit
// i.e 1 to 0 or vice versa. Below this code I have written my trie code. Both the codes are easy 
// to understand. But the second code is much efficient and don't give TLE.
// Time Complexity - O(n2), Space Complexity - O(32*n) or O(n)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<bitset<31>> ans;
        for (int i = 0; i < nums.size(); i++) {
            bitset<31> temp(nums[i]);
            ans.push_back(temp);
        }
        int pos = 30;
        while (pos >= 0) {
            bool flag = false;
            for (int i = 1; i < ans.size(); i++)
                if (ans[i][pos] != ans[i - 1][pos]) {
                    flag = true;
                    break;
                }
            if (flag)
                break;
            pos--;
        }
        if (pos <= 3) {
            int mans = 0;
            for (int i = 0; i < nums.size(); i++)
                for (int j = i + 1; j < nums.size(); j++)
                    mans = max(mans, nums[i] ^ nums[j]);
            return mans;
        }
        vector<vector<int>> mapping(8);
        int maxim = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ans[i][pos] == 0 && ans[i][pos - 1] == 0 && ans[i][pos - 2] == 0)
                mapping[0].push_back(ans[i].to_ulong());
            else if (ans[i][pos] == 0 && ans[i][pos - 1] == 0 && ans[i][pos - 2] == 1)
                mapping[1].push_back(ans[i].to_ulong());
            else if (ans[i][pos] == 0 && ans[i][pos - 1] == 1 && ans[i][pos - 2] == 0)
                mapping[2].push_back(ans[i].to_ulong());
            else if (ans[i][pos] == 0 && ans[i][pos - 1] == 1 && ans[i][pos - 2] == 1)
                mapping[3].push_back(ans[i].to_ulong());
            else if (ans[i][pos] == 1 && ans[i][pos - 1] == 0 && ans[i][pos - 2] == 0)
                mapping[4].push_back(ans[i].to_ulong());
            else if (ans[i][pos] == 1 && ans[i][pos - 1] == 0 && ans[i][pos - 2] == 1)
                mapping[5].push_back(ans[i].to_ulong());
            else if (ans[i][pos] == 1 && ans[i][pos - 1] == 1 && ans[i][pos - 2] == 0)
                mapping[6].push_back(ans[i].to_ulong());
            else
                mapping[7].push_back(ans[i].to_ulong());
        }
        for (int i = 0; i < mapping[0].size(); i++)
            for (int j = 0; j < mapping[7].size(); j++)
                maxim = max(maxim, mapping[0][i] ^ mapping[7][j]);
        for (int i = 0; i < mapping[1].size(); i++)
            for (int j = 0; j < mapping[6].size(); j++)
                maxim = max(maxim, mapping[1][i] ^ mapping[6][j]);
        for (int i = 0; i < mapping[2].size(); i++)
            for (int j = 0; j < mapping[5].size(); j++)
                maxim = max(maxim, mapping[2][i] ^ mapping[5][j]);
        for (int i = 0; i < mapping[4].size(); i++)
            for (int j = 0; j < mapping[3].size(); j++)
                maxim = max(maxim, mapping[4][i] ^ mapping[3][j]);
        return maxim;
    }
};

// Second solution using tries
// I have created a trie of all the numbers and then for each number I looked for its opposite
// bit in the trie. And computed xor and returned maximum xor as answer.
// Time Complexity - O(64n) or O(n), Space Complexity - O(n)
// I have written 64 here as it is not a small constant.
class Solution {
public:   
    struct trie {
        trie *left = NULL, *right = NULL;
    };
    
    void insert(trie *root, bitset<31> &num, int &pos) {
        trie *temp = root;
        for (int i = pos; i >= 0; i--)
            if (num[i] == 0) {
                if (temp->left == NULL)
                    temp->left = new trie();
                temp = temp->left;
            }
            else {
                if (temp->right == NULL)
                    temp->right = new trie();
                temp = temp->right;
            }
    }
    
    int calculateAnswer(trie *root, int &val, int &pos) {
        bitset<31> temp(val), ans;
        trie *head = root;
        for (int i = pos; i >= 0; i--) {
            if (temp[i] == 0)
                if (head->right != NULL) {
                    head = head->right;
                    ans[i] = 1;
                }
                else {
                    ans[i] = 0;
                    head = head->left;
                }
            else
                if (head->left != NULL) {
                    head = head->left;
                    ans[i] = 0;
                }
                else {
                    head = head->right;
                    ans[i] = 1;
                }
        }
        return (temp^ans).to_ulong();
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int pos = 30;

        trie *head = new trie();
        for (int i = 0; i < nums.size(); i++) {
            bitset<31> temp(nums[i]);
            insert(head, temp, pos);
        }
        
        int mxor = 0;
        
        for (auto i: nums)
            mxor = max(calculateAnswer(head, i, pos), mxor);
        
        return mxor;
    }
};