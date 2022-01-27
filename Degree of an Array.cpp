// https://leetcode.com/problems/degree-of-an-array/
// What we know is that if we know the first and last occurence of a particular element then we can easily tell its
// size, now we have to minimize it. So we first computed the largest occurence which is reqd.
// then for that no. of occurences we computed the size and returned it.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> first_occ(50000, -1), last_occ(50000, -1);
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (first_occ[nums[i]] == -1)
                first_occ[nums[i]] = i;
            last_occ[nums[i]] = i;
        }
        int largest = -1, si = 50000;
        for (auto i = freq.begin(); i != freq.end(); i++)
            largest = max(i->second, largest);
        for (auto i : freq)
            if (i.second == largest)
                si = min(si, last_occ[i.first] - first_occ[i.first] + 1);
        return si;
    }
};