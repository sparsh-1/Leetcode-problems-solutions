// https://leetcode.com/problems/valid-parentheses/
// I have used stack to keep track of opening and closing brackets. I a bracket opens 
// then that particular bracket should close first before closing of any other bracket.
// Another case is if the stack still have some elements it means that starting
// of string have some redundant opening parentheses. So it is invalid too.
// Time Complexity - O(s.size), Space Complexity - O(s.size)
class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for (int i = 0; i < s.size(); i++) {
            if (ans.empty() && (s[i] == '}' || s[i] == ')' || s[i] == ']'))
                return false;
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                ans.push(s[i]);
            else if (s[i] == '}')
                if (ans.top() == '{')
                    ans.pop();
                else
                    return false;
            else if (s[i] == ')')
                if (ans.top() == '(')
                    ans.pop();
                else
                    return false;
            else
                if (ans.top() == '[')
                    ans.pop();
                else
                    return false;
        }
        if (ans.empty())
            return true;
        return false;
    }
};