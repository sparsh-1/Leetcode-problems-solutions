// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// We know that the sum can be equalt to only total sum / 3. So we check if it is divisible by 3
// or not and return answer if not. Then as soon as we found two left and right pointers
// pointing to the exact same sum, then we can say that the part in between is the remaining sum
// Also we need to take care for the zero case and there should be atleast 1 number left
// in between.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int ans = accumulate(arr.begin(), arr.end(), 0), i = 0, j = arr.size() - 1, lsum = arr[0], rsum = arr.back();
        if (ans % 3 != 0)
            return false;
        int average = ans / 3;
        while (i < j - 1) {
            if ((lsum == rsum) && (rsum == average) && (j - i) > 1)
                return true;
            if (lsum != average)
                lsum += arr[++i];
            if (rsum != average)
                rsum += arr[--j];
        }
        return false;
    }
};