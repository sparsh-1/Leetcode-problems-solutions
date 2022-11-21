// https://leetcode.com/problems/number-of-unequal-triplets-in-array/
// First Approach - I have just used the brute force i.e. gone through all the triplets in the vector and checked if
// they are all unique.
// Time Complexity - O(n^2), Space Complexity - O(1)
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                for (int k = j + 1; k < nums.size(); k++)
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i])
                        cnt++;
        return cnt;
    }
};

// Second Approach - This approach I got through discuss section of leetcode(https://leetcode.com/problems/number-of-unequal-triplets-in-array/discuss/2831702/O(n))
// Here firstly we created a map of numbers and stored the frequencey of the numbers. After that it is taking a specific pointer first
// at 1st element considering it as the middle em=lement and checks how many numbers are to the left of it and how many are to the right of it, since
// there are no left side elements on 1st element so, 0 triplets possible, now it took 2nd element and check how many left elements are there
// and how many right elements are there multiplied by the element present at 2nd position. the process goes on.
// It is working because we are always choosing 3 unique elements, 1 left, 1 mid and 1 right.
// Time Complexity - O(N) Space Comlexity - O(N)
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        map<int, int> mp;
        for (int n : nums)
            mp[n]++;
        int ans = 0, left = 0;
        for (auto [n, cnt] : mp) {
            ans += left * cnt * (nums.size() - cnt - left);
            left += cnt;
        }
        return ans;
    }
};