// https://leetcode.com/problems/power-of-two/
// Just divided the number by 2 reptitively till it gets divided, if the last answer came out to be 1
// then it is true otherwise false
// Time Complexity - O(1)[We can say it as there can be max of 31 iterations],
// Space Complexity - O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;
        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else
                return false;
        }
        return true;
    }
};

// Bit manipulation logic
// Time complexity - O(1), Space Complexity - O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};

// STL __builtin_popcount
// Time complexity - O(1), Space Complexity - O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return __builtin_popcount(n) == 1;
    }
};