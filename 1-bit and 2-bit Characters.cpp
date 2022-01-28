// https://leetcode.com/problems/1-bit-and-2-bit-characters/
// If the second last character is 0, then no matter what the answer will always be true
// otherwise we have to check
//Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 2 && bits[0] == 1)
            return bits[0] == 0;
        if (bits.size() > 2 && bits[bits.size() - 2] == 0)
            return true;
        int i = 0;
        for (; i < bits.size();) {
            if (bits[i] == 1)
                i += 2;
            if (i == bits.size() - 1)
                return true;
            if (i < bits.size() && bits[i] == 0)
                i++;
        }
        return false;
    }
};