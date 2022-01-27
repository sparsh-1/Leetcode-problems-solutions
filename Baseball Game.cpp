// https://leetcode.com/problems/baseball-game/
// We can see clearly that the operations given can be applied very easily on stack 
// So we used stack.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> ans;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                int temp = ans.top();
                ans.pop();
                int news = ans.top() + temp;
                ans.push(temp);
                ans.push(news);
            }
            else if (ops[i] == "C")
                ans.pop();
            else if (ops[i] == "D")
                ans.push(ans.top() * 2);
            else
                ans.push(stoi(ops[i]));
        }
        int res = 0;
        while (ans.size()) {
            res += ans.top();
            ans.pop();
        }
        return res;
    }
};