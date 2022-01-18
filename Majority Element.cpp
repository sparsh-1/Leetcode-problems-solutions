// https://leetcode.com/problems/majority-element/
// Approach 1 - Directly used map to store frequency of elements
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        for (auto i: freq)
            if (i.second > nums.size() / 2)
                return i.first;
        return 0;
    }
};

// Approach 2 - Using O(1) Space complexity and O(n) time complexity
// Boyer-Moore's majority voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == elem)
                count++;
            else {
                count--;
                if (count == 0) {
                    elem = nums[i];
                    count = 1;
                }
            }
        return elem;
    }
};
// In this above approach if some element is present in majority i.e > n / 2
// then it will definitely remain till the last. It is like voting up for
// a candidate, if opposition is more for one candidate then its count will
// become 0, and then for that number itself we will pick it as a potential
// candidate.
// Second part of this algorithm is to check whether this number is really 
// occurring more than n / 2 times which is not required here as it is given
// in question that exactly 1 element is majority element.