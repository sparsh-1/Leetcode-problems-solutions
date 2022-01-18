// https://leetcode.com/problems/task-scheduler/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(int i = 0; i < tasks.size(); i++)
            freq[tasks[i] - 'A']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int i = 0;
        if (n == 0)
            return tasks.size();
        int idle = (freq[0] - 1) * n, ans = 0, same = 0;
        for(int i = 1; i < 26; i++) {
            if (freq[i] == freq[0])
                same++;
            ans += freq[i];
        }
        if (ans - same >= idle)
            return tasks.size();
        else
            return freq[0] + idle + same;
    }
};