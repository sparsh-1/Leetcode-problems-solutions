// https://leetcode.com/problems/asteroid-collision/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector <int> sol;
        int j = 0;
        while (j < a.size() && a[j] < 0)
            sol.push_back(a[j++]);
        stack <int> ans;
        for (int i = j; i < a.size(); i++) {
            if (ans.empty())
                ans.push(a[i]);
            else {
                if (a[i] > 0)
                    ans.push(a[i]);
                else {
                    int temp = 10000;
                    while (!ans.empty() && abs(a[i]) > ans.top() && ans.top() > 0) {
                        ans.pop();
                    }
                    if (!ans.empty() && abs(a[i]) == ans.top())
                        ans.pop();
                    else {
                        if (ans.empty())
                            ans.push(a[i]);
                        else if (!ans.empty() && ans.top() < 0)
                            ans.push(a[i]);
                    }
                }
            }
        }
        stack <int> nya;
        while (!ans.empty()) {
            nya.push(ans.top());
            ans.pop();
        }
        while (!nya.empty()) {
            sol.push_back(nya.top());
            nya.pop();
        }
        return sol;
    }
};