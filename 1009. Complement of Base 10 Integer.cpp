// https://leetcode.com/problems/complement-of-base-10-integer/
// What I have done here is that I converted the number to bitset and then changed 1 bits to 0 and 0s bit to 1 
// till the leftmost 1 bit.
// Time Complexity - O(1), Space Complexity - O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        bitset<32> b(n);
        int last = 0;
        for (int i = 0; i < 31; i++)
            if (b[i])
                last = i;
        for (int i = 0; i <= last; i++)
            b[i] = ~b[i];
        return b.to_ulong();
    }
};

// Converting to bitset is a costly operation, we can directly use masking and convert bits.
// Here we have used negate operator on original number, so it will convert all 1 to 0 and 0 to 1, but the leftmost 0
// are only required as 0 which have now become 1. So to conquer this we have created a mask which will be something
// like 00000...11111, which we will do and with ~n then we will remove the left 1's as 0s and all the negation will
// stay intact.
// Time Complexity - O(1), Space Complexity - O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int mask = 0, m = n;
        while (m != 0) {
            m = m >> 1;
            mask = (mask << 1) | 1;
        }
        return ~n & mask;
    }
};