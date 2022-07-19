// https://leetcode.com/problems/sliding-window-maximum/
// here, I have used deque data structure to ahieve the best time and space complexity (although can be done in O(1) space, but time is O(nk) or etc)
// I know that only usefl elements are reuired. i.e. If an element is largest in a particular window then I can store that element
// after that if there is any eement which is smaller than it are discarded except the numbers which are greater than the smaller one
// or an element is greater than all its right elements. As the smaller elements can't be answer in any window. So, by using
// these useful elements we can give the answer.
// Time Complexity - O(n) Space Complexity - O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1)
            return nums;
        deque<int> ind;
        vector<int> ans;
        for (int i = 0; i < k; i++)
            if (ind.empty())
                ind.push_back(i);
            else if (nums[ind.front()] <= nums[i]) {
                while (!ind.empty() && nums[ind.front()] <= nums[i])
                    ind.pop_front();
                ind.push_back(i);
            }
            else if (nums[ind.back()] <= nums[i]) {
                while (!ind.empty() && nums[ind.back()] <= nums[i])
                    ind.pop_back();
                ind.push_back(i);
            }
            else
                ind.push_back(i);
        ans.push_back(nums[ind.front()]);
        for (int i = k; i < nums.size(); i++) {
            if (ind.front() <= i - k)
                ind.pop_front();
            if (nums[ind.front()] <= nums[i])
                while (!ind.empty() && nums[ind.front()] <= nums[i])
                    ind.pop_front();
            else if (nums[ind.back()] <= nums[i])
                while (!ind.empty() && nums[ind.back()] <= nums[i])
                    ind.pop_back();
            ind.push_back(i);
            ans.push_back(nums[ind.front()]);
        }
        return ans;
    }
};