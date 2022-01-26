// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// I have computed the gcd of all numbers, if it is more than or equal to 2 it means that
// numbers can be divided equally in more than 2 parts
// Time Complexity - O(n * log(C)^2), Space Complexity - O(n)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> freq;
        for (int i = 0; i < deck.size(); i++)
            freq[deck[i]]++;
        int gd = freq.begin()->second;
        for (auto i = freq.begin(); i != freq.end(); i++) {
            gd = __gcd(i->second, gd);
            if (gd <= 1)
                return false;
        }
        return true;
    }
};