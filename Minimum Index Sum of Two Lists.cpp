// https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// I just have stored all the strings into a map along with their index, then I am checking
// for second list strings if they exists in the map. If they exists then I check nearest index first
// and add them to our list.
// Time Complexity - O(nlgn*string.size), Space Complexity - O(n*string.size)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        map<string, int> occ;
        for (int i = 0; i < list1.size(); i++)
            occ[list1[i]] = i;
        int cur_min = 2000;
        for (int i = 0; i < list2.size(); i++)
            if (occ.find(list2[i]) != occ.end())
                if (occ[list2[i]] + i < cur_min) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    cur_min = occ[list2[i]] + i;
                }
                else if (occ[list2[i]] + i == cur_min)
                    ans.push_back(list2[i]);
        return ans;
    }
};