// https://leetcode.com/problems/binary-prefix-divisible-by-5/
// We know since the length of array is upto 1e5, so we can't just update the number
// like 2 * prev + (1 or 0) as it will overflow. But we know the property of modulus operator
// that (a * b + c) % d = ((a % d) * (b % d) + c % d) % d;
// Here, a = prev number, b = 2, c = nums[i], d = 5
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num = (num * 2 + nums[i]) % 5;
            ans.push_back(num == 0);
        }
        return ans;
    }
};