// https://leetcode.com/problems/relative-ranks/
// I have used builtin property of map that it stores elements in sorted manner
// So, I have pushed indexes and score with them the first score will be for the 
// last person.
// We can implement the same thing using priority queue.
// Time complexity - O(nlgn), Space Complexity - O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        if (score.size() <= 1)
            return {"Gold Medal"};
        vector<string> ans(score.size());
        map<int, int> place;
        for (int i = 0; i < score.size(); i++)
            place[score[i]] = i;
        int count  = score.size();
        for (auto i : place) {
            if (count == 1)
                ans[i.second] = "Gold Medal", count--;
            else if (count == 2)
                ans[i.second] = "Silver Medal", count--;
            else if (count == 3)
                ans[i.second] = "Bronze Medal", count--;
            else
                ans[i.second] = to_string(count--);
        }
        return ans;
    }
};