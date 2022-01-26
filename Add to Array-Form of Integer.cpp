// https://leetcode.com/problems/add-to-array-form-of-integer/
// What you may see below looks really complicated but it isn't.
// Actually my first code was giving WA on some edge test cases. So, I rectified
// everything in between. What I have done here is to add element one by one
// first ones place, then tens, then hundreth, and so on. In between I am also
// tracking whether a number is carried forward. Also if number k is greater than array
// or due to additional array size increases, we need to add element to first of the
// array. 
// Some edge cases where my previous code was failing are
// [9,9,9,9,9,9,9,9,9,9]
// 1
// [7]
// 993
// Time Complexity - O(max(n, logk)), Space Complexity - O(max(n, logk))
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        bool carry = false;
        while (k != 0 && i >= 0) {
            int addition = num[i] + (k % 10);
            if (carry)
                addition++;
            carry = false;
            if (addition > 9) {
                carry = true;
                num[i] = addition % 10;
            }
            else
                num[i] = addition;
            k /= 10, i--;
        }
        if (carry)
            for (; i >= 0; i--)
                if (num[i] + 1 > 9)
                    num[i] = 0;
                else {
                    carry = false;
                    num[i]++;
                    break;
                }
        if (!carry && k == 0)
            return num;
        if (carry && k == 0) {
            vector <int> ans;
            ans.push_back(1);
            for (int i = 0; i < num.size(); i++)
                ans.push_back(num[i]);
            return ans;
        }
        vector<int> ans;
        string remains = to_string(k);
        for (int i = 0; i < remains.size(); i++)
            ans.push_back(remains[i] - '0');
        if (carry)
            for (int i = remains.size() - 1; i >= 0; i--)
                if (ans[i] + 1 > 9)
                    ans[i] = 0;
                else {
                    carry = false;
                    ans[i]++;
                    break;
                }
        if (carry) {
            ans.push_back(ans.back());
            for (int i = ans.size() - 2; i > 0; i--)
                ans[i] = ans[i - 1];
            ans[0] = 1;
        }
        for (int i = 0; i < num.size(); i++)
            ans.push_back(num[i]);
        return ans;
    }
};