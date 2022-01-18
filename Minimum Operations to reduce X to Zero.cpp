// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> presum(nums.size(), nums[0]), postsum(nums.size(), nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); i++)
            presum[i] = presum[i - 1] + nums[i];
        for (int i = nums.size() - 2; i >= 0; i--)
            postsum[i] = postsum[i + 1] + nums[i];
        int i = 0, j = nums.size() - 1;
        if (presum[0] > x) {
            while (j >= 0 && postsum[j] < x)
                j--;
            if (j == -1)
                j++;
            if (postsum[j] == x)
                return nums.size() - j;
            else if (j < nums.size() - 1 && postsum[j + 1] == x)
                return nums.size() - j + 1;
            else
                return -1;
        }
        if (postsum[nums.size() - 1] > x) {
            while (i < nums.size() && presum[i] < x)
                i++;
            if (i == nums.size())
                i--;
            if (presum[i] == x)
                return i + 1;
            else if (i > 0 && presum[i - 1] == x)
                return i;
            else
                return -1;
        }
        while (i < j) {
            if (presum[i] < x)
                i++;
            else
                break;
        }
        int ans = 1e9;
        if (presum[i] == x)
            ans = i + 1;
        if (presum[i] > x)
            i -= 1;
        while (i >= 0 && i < j) {
            if (i == 0 && postsum[j] == x)
                ans = min(ans, (int)(nums.size() - j));
            if (presum[i] + postsum[j] == x)
                ans = min(ans, (int)(i-- + 1 + nums.size() - j));
            else if (presum[i] + postsum[j] > x)
                i--;
            else
                j--;
            if (i <= 0 && postsum[j] == x)
                ans = min(ans, (int)(nums.size() - j));
        }
        if (ans != 1e9)
            return ans;
        return -1;
    }
};

//2nd approach (took more time and space than 1st approach)(P.S - map takes even more than unordered one)
int minOperations(vector<int>&nums, int x) {
        unordered_map<int, int> m;
        int suma = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i] + suma] = i + 1;
            suma += nums[i];
        }
        suma = 0;
        int mina = 1e9;
        if (m.find(x) != m.end())
            mina = m[x];
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (x - nums[j] - suma < 0)
                break;
            if (m.find(x - nums[j] - suma) != m.end() && m[x - nums[j] - suma] + nums.size() - j < nums.size()) {
                mina = min(mina, (int)(nums.size() - j + m[x - nums[j] - suma]));
            }
            else if (suma + nums[j] == x)
                mina = min(mina, (int)(nums.size() - j));
            suma += nums[j];
        }
        if (mina != 1e9)
            return mina;
        return -1;
    }