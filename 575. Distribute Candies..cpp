// https://leetcode.com/problems/distribute-candies/
// I have just stored unique types of candies, if they are more I return arr.size() / 2 otherwise i return set size.
// Time Complexity - O(nlgn) [If we use unordered_set then average O(n)] Space Complexity - O(n)
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> mp(candyType.begin(), candyType.end());
        return min(candyType.size() / 2, mp.size());
    }
};