// https://leetcode.com/problems/add-binary/
// My approach seems a bit lengthy but it will explain you all the cases of binary addition.
// If we have carry and both numbers are positive then we should maintain carry and make the number 0, 
// similarly we will be handling different cases.
// Time Complexity - O(max(a.size, b.size())), Space Complexity - O(max(a.size, b.size()))
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0, ptr = 0;
        while (ptr < min(a.size(), b.size())) {
            if (a[ptr] == '1' && b[ptr] == '1' && carry)
                ans += '1';
            else if (a[ptr] == '1' && b[ptr] == '1')
                ans += '0', carry = 1;
            else if (a[ptr] == '1' && carry)
                ans += '0';
            else if (a[ptr] == '1')
                ans += '1';
            else if (b[ptr] == '1' && carry)
                ans += '0';
            else if (b[ptr] == '1')
                ans += '1';
            else if (carry)
                ans += '1', carry = 0;
            else
                ans += '0';
            ptr++;
        }
        while (ptr < a.size()) {
            if (carry && a[ptr] == '1')
                ans += '0';
            else if (carry)
                ans += '1', carry = 0;
            else if (a[ptr] == '1')
                ans += '1';
            else
                ans += '0';
            ptr++;
        }
        while (ptr < b.size()) {
            if (carry && b[ptr] == '1')
                ans += '0';
            else if (carry)
                ans += '1', carry = 0;
            else if (b[ptr] == '1')
                ans += '1';
            else
                ans += '0';
            ptr++;
        }
        if (carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};