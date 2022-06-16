// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Here I have used all the elements occuring in the array as the pointers to the desired location i.e. if 3 is present at 
// some position x in the array it is pointing to location 3. Now not to change the index 3 I have just inversed 
// the value at that position that I have already found atleast 1 value which is pointing to that specific position.
// Now, if I again find some same element then I know that value at that position is already negative i.e. this number
// has occured in some previous part of the array.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                if (nums[nums[i] - 1] > 0)
                    nums[nums[i] - 1] = -nums[nums[i] - 1];
                else
                    ans.push_back(nums[i]);
            else
                if (nums[-nums[i] - 1] > 0)
                    nums[-nums[i] - 1] = -nums[-nums[i] - 1];
                else
                    ans.push_back(-nums[i]);
        return ans;
    }
};