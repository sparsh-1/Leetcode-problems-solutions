// // https://leetcode.com/problems/intersection-of-two-arrays/
// Used hashing using arrays, as elements can range from 1 to 1000 only
// so retrieval and assignment can be done in only O(1)
// Time Complexity - O(nums1.len + nums2.len), Space complexity - O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(1001), ans;
        for (int i = 0; i < nums1.size(); i++)
            arr[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++)
            if (arr[nums2[i]])
                ans.push_back(nums2[i]), arr[nums2[i]]--;
        return ans;
    }
};

// Let us given in the question that the arrays are sorted
// Time Complexity - O(nums1.len + nums2.len), Space complexity - O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int one = 0, two = 0;
        while (one < nums1.size() && two < nums2.size()) {
            while (one < nums1.size() && nums1[one] < nums2[two])
                one++;
            while (two < nums2.size() && nums1[one] > nums2[two])
                two++;
            if (one < nums1.size() && two < nums2.size() && nums1[one] == nums2[two])
                ans.push_back(nums1[one++]), two++;
        }
        return ans;
    }
};

// Let us given another case when one array size is too small compared to other
// We can use binary search for the small array then
// Time complexity - O(max(nums1.len, nums2.len)), Space Complexity - O(1)
