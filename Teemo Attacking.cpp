// https://leetcode.com/problems/teemo-attacking/
// Basically I have checked whether the poision is still effective till current time,
// if it is, i move on to next position and check for same, otherwise I will add
// the duration plus the effect from when he is previously poisoned
// Time complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, start = timeSeries[0];
        int i = 1;
        while (i < timeSeries.size()) {
            if (timeSeries[i] - duration + 1 <= timeSeries[i - 1])
                i++;
            else {
                ans += timeSeries[i - 1] - start + duration;
                start = timeSeries[i++];
            }
        }
        return ans + timeSeries.back() - start + duration;
    }
};