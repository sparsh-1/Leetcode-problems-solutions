// https://leetcode.com/problems/stone-game-iv/
// This is a Game theory and DP problem.
// What I have done here is that if for any of the index - square number == 2
// i.e bob wins the game then alice will play that move so, that 2nd player that is 
// again alice will win.
// Time complexity - O(n*sqrt(n)), Space Complexity - O(n + sqrt(n))
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> arr(n + 1, 1), squares(sqrt(n + 1));
        int cnt = 0;
        for (int i = 2; i < n + 1; i++) {
            int sqrts = sqrt(i);
            if (i == sqrts * sqrts)
                squares[cnt++] = i;
            else {
                arr[i] = arr[i - 1] == 1 ? 2 : 1;
                if (arr[i] == 2) {
                    for (int j = cnt - 1; j >= 0; j--)
                        if (arr[i - squares[j]] == 2) {
                            arr[i] = 1;
                            break;
                        }
                }
            }
        }
        if (arr[n] == 1)
            return true;
        return false;
    }
};

// While observing other person codes, I saw that Space complexity can be further reduced
// We can run a while loop for squares in the same array, and can also make this array
// as boolean array.
// for every winning tile of 2nd player if we subtract a square number then alice
// will win, same logic as above.
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> win(n + 1, 0);
        for (int i = 0; i <= n; i++)
            if (!win[i])
                for (int j = 1; (i + j * j) <= n; j++)
                    win[j * j + i] = 1;
        return win[n];
    }
};