// https://leetcode.com/problems/distribute-candies/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set <int> arr(candyType.begin(), candyType.end());
        if (arr.size() <= candyType.size() / 2)
            return arr.size();
        else
            return candyType.size() / 2;
    }
};