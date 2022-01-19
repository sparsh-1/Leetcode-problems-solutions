// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
// I have created a boolean array and check whether each number is occuring or not.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<bool> chk(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++)
            chk[nums[i]] = 1;
        for (int i = 1; i <= nums.size(); i++)
            if (!chk[i])
                ans.push_back(i);
        return ans;
    }
};

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/1583736/C%2B%2BPython-All-6-Solutions-w-Explanations-or-Binary-Search%2B-Hashset-%2B-2x-O(1)-Space-Approach
// The above link is really a very nice explanation to the above question.
// I even got wonderful approaches like in place sorting and negation from here only.
// The above both use T.C - O(n) and S.C - O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                ans.push_back(i + 1);
        return ans;
            
    }
};