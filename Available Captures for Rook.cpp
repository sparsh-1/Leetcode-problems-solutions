// https://leetcode.com/problems/available-captures-for-rook/
// hardcoded solution - First we took out the place of rook occurence then for its top
// left right and bootom we check whether first a pawn occurs, if it occurs then we increment
// count by 1
// Time Complexity - O(n*n), Space Complexity - O(1)
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rooki, rookj, i, j, count = 0;
        for (i = 0; i < 8; i++) {
            bool flag = false;
            for (j = 0; j < 8; j++)
                if (board[i][j] == 'R') {
                    rooki = i, rookj = j;
                    flag = true;
                    break;
                }
            if (flag)
                break;
        }
        cout << rooki << " " << rookj << "\n";
        i = rooki - 1, j == rookj;
        while (i >= 0) {
            if (board[i][j] == 'B')
                break;
            if (board[i--][j] == 'p') {
                count++;
                break;
            }
        }
        cout << count << "\n";
        i = rooki, j--;
        while (j >= 0) {
            if (board[i][j] == 'B')
                break;
            if (board[i][j--] == 'p') {
                count++;
                break;
            }
        }
        cout << count << "\n";
        j = rookj + 1;
        while (j < 8) {
            if (board[i][j] == 'B')
                break;
            if (board[i][j++] == 'p') {
                count++;
                break;
            }
        }
        cout << count << "\n";
        j = rookj, i++;
        while (i < 8) {
            if (board[i][j] == 'B')
                break;
            if (board[i++][j] == 'p') {
                count++;
                break;
            }
        }
        return count;
    }
};