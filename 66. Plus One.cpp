// https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        
        if (digits[digits.size() - 1] != 9) {
            digits[digits.size() - 1]++;
            return digits;
        }
        else {
            digits[digits.size() - 1] = 0;
            carry = true;
        }
        
        for (int i = digits.size() - 2; i >= 0; i--)
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        
        digits.push_back(0);
        digits[0] = 1;
        
        return digits;
    }
};