// https://leetcode.com/problems/add-digits/
// Just divided the number and perform summation till it remains to a single digit
// Time Complexity - , Space Complexity - O(1)
class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while (num != 0) {
            while (num != 0) {
                ans += (num % 10);
                num /= 10;
            }
            num = ans;
            ans = 0;
            if (num <= 9)
                return num;
        }
        return 0;
    }
};

// Second solution
// This process is known as to derieve digital number(or digital root) of a specific number
// If number is 0 then answer is 0, if it is multiple of 9 then answer is 9 else
// is is num % 9;
// Time Complexity - O(1), Space Complexity - O(1)
class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        else if (num % 9 == 0)
            return 9;
        else
            return num % 9;
    }
};