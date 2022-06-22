// https://leetcode.com/problems/climbing-stairs/
// I have used recursion with map here so that I can keep the value from the ith stair.
// I just see what are the number of ways from stairs with n - 2 steps or n - 1 steps.
// Time Complexity - O(n) Space Complexity - O(n)
class Solution {
public:
    map<int, int> mp;
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;
        int a, b;
        if (mp.find(n - 1) != mp.end())
            a = mp[n - 1];
        else {
            a = climbStairs(n - 1);
            mp[n - 1] = a;
        }
        if (mp.find(n - 2) != mp.end())
            b = mp[n - 2];
        else {
            b = climbStairs(n - 2);
            mp[n - 2] = b;
        }
        return a + b;
    }
};

// Time Optimized Approach
// I have used concept of DP here, I know that if stair have 1 step, then no. of ways = 1
// The key intuition to solve the problem is that given a number of stairs n, if we know the 
// number ways to get to the points [n-1] and [n-2] respectively, denoted as n1 and n2 , then 
// the total ways to get to the point [n] is n1 + n2. Because from the [n-1] point, we can take
//  one single step to reach [n]. And from the [n-2] point, we could take two steps to get there. 
// Time Complexity - O(n) Space Complexity - O(n)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;
        vector<int> arr(n, 1);
        arr[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--)
            arr[i] = arr[i + 1] + arr[i + 2];
        return arr[0];
    }
};

// Time and space optimized approach
// We know that only last 2 indexes are required, so we only need 2 variables not the whole array
// Time Complexity - O(n) Space Complexity - O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;
        int a = 2, b = 1;
        for (int i = n - 3; i >= 0; i--) {
            b += a;
            swap(a, b);
        }
        return a;
    }
};