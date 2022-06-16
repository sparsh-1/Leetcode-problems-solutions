// https://leetcode.com/problems/reverse-integer/
// I have just simply reversed the integer keeping the edge cases in mind.
// Time Complexity - O(logx), Space Complexity - O(1)
class Solution {
public:
    int reverse(int x) {
        if (((x % 10 > 2) && x / 1000000000 > 0) || x == -2147483648) 
            return 0;
        bool flag = false;
        if (x < 0) {
            x = -x;
            flag = true;
        }
        int ans = x % 10;
        x /= 10;
        while (x != 0) {
            if (ans >= 214748364)
                if (ans > 214748364 || x % 10 > 7)
                    return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if (flag)
            ans *= -1;
        return ans;
    }
};