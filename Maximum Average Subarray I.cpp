// https://leetcode.com/problems/maximum-average-subarray-i/
// I have used the concept of sliding window. Instead of calculating the sum again and again
// for k integers. I compute the sum for previous k integeres and for next I knwo the sum will
// be equal to sum + next element - previous element at i - k location.
// Then I just returned the maximum average.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double> ans;
        double sums = 0;
        for (int i = 0; i < k; i++)
            sums += nums[i];
        ans.push_back((double)(sums / (double)k));
        for (int i = k; i < nums.size(); i++) {
            sums += nums[i] - nums[i - k];
            ans.push_back(sums / (double)k);
        }
        return *max_element(ans.begin(), ans.end());
    }
};

// On a second thought I think that we don't need the whole array. So I just replace array with a single ans.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        double sums = 0;
        for (int i = 0; i < k; i++)
            sums += nums[i];
        ans = (double)(sums / (double)k);
        for (int i = k; i < nums.size(); i++) {
            sums += nums[i] - nums[i - k];
            ans = max(ans, sums / (double)k);
        }
        return ans;
    }
};

// I am just smiling at myself thinking how well we can optimize the solution. We just need to keep track o 
// the maximum sum. The actual answer will be anymays maximum sum / k
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        double sums = 0;
        for (int i = 0; i < k; i++)
            sums += nums[i];
        ans = sums;
        for (int i = k; i < nums.size(); i++) {
            sums += nums[i] - nums[i - k];
            ans = max(ans, sums);
        }
        return ans / k;
    }
};