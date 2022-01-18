// https://leetcode.com/problems/largest-number/
bool comp(string a, string b) {
        return (a + b) > (b + a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> arr;
        for (int i = 0; i < nums.size(); i++) 
            arr.push_back(to_string(nums[i]));
        sort(arr.begin(), arr.end(), comp);
        string a;
        for (int i = 0; i < arr.size(); i++)
            a += arr[i];
        long long i = 0;
        while (i < a.size() and a[i] == '0')
            i++;
        if (i < a.size())
            return a.substr(i, a.size() - i);
        else
            return "0";
    }
};