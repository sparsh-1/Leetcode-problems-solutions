// https://leetcode.com/problems/set-mismatch/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector <int> arr(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        int two = 0, no = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == 1)
                continue;
            else if (arr[i] == 0)
                no = i;
            else
                two = i;
            if (no && two)
                break;
        }
        vector <int> ans {two, no};
        return ans;
    }
};