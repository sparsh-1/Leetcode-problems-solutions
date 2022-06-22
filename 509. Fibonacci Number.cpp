// https://leetcode.com/problems/fibonacci-number/
// We know first and second fibonacci numbers are 0 and 1 respectively. Now, to reach the nth
// fibonacci number we just need to know the previous two fibonacci number and sum them up.
// Time Complexity - O(2^n) Space Complexity - O(n)
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};


// Time and Space Optimized approach
// Here, we only needed previous 2 values so, I just used 2 variables and computed their sum
// n times and returned it.
// Time Complexity - O(n) Space Complexity - O(1)
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        int a = 1, b = 0;
        for (int i = 2; i <= n; i++) {
            b += a;
            swap(a, b);
        }
        return a;
    }
};