// https://leetcode.com/problems/maximum-score-from-removing-stones/
// What I have done here is that, I know T have to make the largest 2 elements equal either by diminishing the lowest
// number or not by diminishing it. Then if it is diminished then I will group 2nd and 3rd number together and reach
// maximmum score. If it is not diminished, then the answer will be the moves to make 2nd and 3rd element equal and
// after that I pick 1 stone from 1st pile and alternately other stone from 2nd and 3rd pile to keep these 2nd and 3rd 
// pile equal or with a difference of 1.
// Time Complexity - O(1), Space Complexity - O(1)
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        int ans = 0;
        if (arr.back() - arr[1] < arr[0]) {
            ans += arr.back() - arr[1];
            arr[0] -= arr.back() - arr[1];
            arr.back() = arr[1];
            
            if (arr[0] & 1)
                ans += arr[0] - 1;
            else
                ans += arr[0];
            
            arr[1] -= arr[0] / 2;
            arr.back() -= arr[0] / 2;
            
            return ans + arr.back();
        }
        else {
            return arr[0] + min(arr[1], arr[2]);
        }
        return 0;
    }
};