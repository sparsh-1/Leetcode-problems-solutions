// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Here, I have used queue, I am storing all elements from 1 to n, then pop k - 1 elements and pushed them at the back 
// after that i removed the kth element. I repeat this process till there is only 1 element left.
// Time Complexity - O(n*k) Space Complexity - O(n)
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            int x=k;
            while(x>1){
                int r=q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
};

// Time Complexity Optimized
// I have observed a pattern that if I know the answer to n - 1, k people I just simply needed to add f(n-1, k) + k
// and take mod with n. Now since it is 1 indexed I also needed to add 1 to the answer.
// Time Complexity - O(n) Space Complexity - O(n)
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;
        return (findTheWinner(n- 1, k) + k - 1) % n + 1;
    }
};
class Solution {
public:
    int helper(int n,int k){
        if(n==1)
            return 0;
        return (helper(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   // +1 is for converting 0-based indexing to 1-based indexing
    }
};

// Time and space optimized approach
// Just used the recursion approach pattern using a for loop
// Time Complexity - O(n) Space Complexity - O(1)
class Solution {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for conterting 0-based indexing to 1-based indexing
    }
};
