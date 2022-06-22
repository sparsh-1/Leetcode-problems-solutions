// https://leetcode.com/problems/single-number/
// We know the property of XOR that if two numbers are equal then xor of those numbers is 0.
// So by using this property we just XOR all numbers and the numbers which are occuring twice resulted 0, and 0 xor any 
// number is that number itself. So, we successfully found our answer.
// Time Complexity - O(n) Space Complexity - O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
            nums[i] ^= nums[i - 1];
        return nums[nums.size() - 1];
    }
};