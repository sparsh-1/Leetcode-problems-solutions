// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// I have calculated the sum and the absolute minimum element firsthand
// Then I sorted the array and then for min k or min negative numbers I just negated them
// Then I know that only the minimum number should be negated back and forth. So, I gave
// answer accoding to that.
// Time Complexity - O(nlgn), Space Complexity - O(1)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int negi = 0, suma = 0, amina = 100;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                negi++;
            suma += nums[i];
            amina = min(abs(nums[i]), amina);
        }
        int temp = min(k, negi);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < temp; i++)
            suma += 2 * -nums[i];
        k -= temp;
        negi -= temp;
        if (negi == 0)
            if (k % 2)
                return suma - 2 * amina;
            else
                return suma;
        else if (negi >= k)
            return suma;
        else
            if (k % 2)
                return suma - 2 * amina;
            else
                return suma;
        return -1;
    }
};