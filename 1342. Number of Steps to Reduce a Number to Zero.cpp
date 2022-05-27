// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// As I have seen the constraints that the numbers are till 1e6 only, so I have directly done what is stated in the question.
// Time Complexity - O(log2(n)), Space Complexity - O(1).
class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num != 0)
            if (num % 2)
                cnt++, num--;
            else
                num = num / 2, cnt++;
        return cnt;
    }
};

// But there is a more efficient approach available too
// One liner answer by Errichto, __builtin_popcount gives the number of 1s in the binary representation of a number
// and __builtin_clz Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;


// Another beautifully written solution
// For the binary representation from right to left(until we find the leftmost 1):
// if we meet 0, result += 1 because we are doing divide;
// if we meet 1, result += 2 because we first do "-1" then do a divide;
// only exception is the leftmost 1, we just do a "-1" and it becomse 0 already.
int numberOfSteps (int num) {
		if(!num) return 0;
        int res = 0;
        while(num) {
            res += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return res - 1;
    }