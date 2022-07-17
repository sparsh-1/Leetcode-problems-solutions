// https://leetcode.com/problems/spiral-matrix-iv/
// I just have followed the simple instructions that are given in the question along with checking 
// whether my linked list is empty or not. I linked list become empty I return the answer, as I have set
// the default values as -1 only.
// Time Complexity - O(m * n) Space Complexity - O(m * n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int start_i = 0, start_j = 0, end_i = m - 1, end_j = n - 1;
        while (head != nullptr) {
            int si = start_i, ei = end_i, sj = start_j, ej = end_j;
            while (head != nullptr && start_j <= end_j) {
                // cout << 1 << start_i << " " << start_j << " " << end_i << " " << end_j << "\n";
                ans[start_i][start_j++] = head->val;
                head = head->next;
            }
            start_j = sj;
            start_i++;
            while (head != nullptr && start_i < end_i) {
                // cout << 2 << start_i << " " << start_j << " " << end_i << " " << end_j << "\n";
                ans[start_i++][end_j] = head->val;
                head = head->next;
            }
            start_i = si + 1;
            while (head != nullptr && end_j >= start_j) {
                // cout << 3 << start_i << " " << start_j << " " << end_i << " " << end_j << "\n";
                ans[end_i][end_j--] = head->val;
                head = head->next;
            }
            end_j = ej - 1;
            end_i--;
            while (head != nullptr && end_i >= start_i) {
                // cout << 4 << start_i << " " << start_j << " " << end_i << " " << end_j << "\n";
                ans[end_i--][start_j] = head->val;
                head = head->next;
            }
            start_j = ++sj;
            end_i = --ei;
        }
        return ans;
    }
};