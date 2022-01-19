// https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int ans = 0;
        if (arr[0] == 1)
            ans++;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == 1)
                arr[i] += arr[i - 1];
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};