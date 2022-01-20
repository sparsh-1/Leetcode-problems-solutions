// https://leetcode.com/problems/koko-eating-bananas/
// Binary search - Since we know if for a particular time koko cannot eat banana
// then for previous times he definitely can't eat bananas i.e we discarded
// the previous half range. And for any time if he can eat bananas then for
// next time he can eat bananas so we need to lookup on the left side.
// Time complexity - O(nlogm), Space complexity - O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        if (h == piles.size())
            return high;
        while (low <= high) {
            int mid = (high + low) / 2;
            int hrs = 0;
            bool flag = true;
            for (int i = 0; i < piles.size(); i++) {
                hrs += (piles[i] + mid - 1) / mid;
                if (hrs > h) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
        
    }
};