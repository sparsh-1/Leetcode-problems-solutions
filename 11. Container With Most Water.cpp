// https://leetcode.com/problems/container-with-most-water/
// Two Pointers
// What I have thought here is that, there might be a brute force approach that for every bar we can traverse to its right
// and calculate the maximum amount of water, but it can cost me a time complexity of
// O(n2) (which can't be run eith the given constraints). Then I came up with two pointers approach.
// I know that the maximum water can be stored in some max heights columns and max seperated
// columns. So, I start at both ends, and calculate the maximum water. Then, the smaller 
// boundary will be storing less amount of water, so I will move the pointer pointing to
// smaller height.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, marea = 0;
        while (i < j) {
            marea = max(marea, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return marea;
    }
};