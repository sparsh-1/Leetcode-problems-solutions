// https://leetcode.com/problems/intersection-of-two-arrays/
// Used hashing using arrays, as elements can range from 1 to 1000 only
// so retrieval and assignment can be done in only O(1)
// Time Complexity - O(max(nums1.len, nums2.len)), Space complexity - O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(1001), ans;
        for (int i = 0; i < nums1.size(); i++)
            arr[nums1[i]] = 1;
        for (int i = 0; i < nums2.size(); i++)
            if (arr[nums2[i]] == 1)
                ans.push_back(nums2[i]), arr[nums2[i]] = 0;
        return ans;
    }
};