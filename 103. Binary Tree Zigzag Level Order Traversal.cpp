// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// I have used stack and queue both here, I know that for each even level I have to traverse from left to right
// and for each odd level, I have to traverse from right to left. I am using stack for reversing the order of traversal in the nxt round.
// Time Complexity - O(n) Space Complexity - O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        stack<TreeNode*> s;
        int lvl = 0;
        while (!q.empty()) {
            lvl++;
            int sz = q.size();
            vector<int> temp;
            while (sz--) {
                TreeNode *t = q.front();
                q.pop();
                if (lvl & 1) {
                    if (t->left)
                        s.push(t->left);
                    if (t->right)
                        s.push(t->right);
                }
                else {
                    if (t->right)
                        s.push(t->right);
                    if (t->left)
                        s.push(t->left);
                }
                temp.push_back(t->val);
            }
            ans.push_back(temp);
            while (!s.empty()) {
                q.push(s.top());
                s.pop();
            }
        }
        return ans;
    }
};


// Using only queue to solve the problem
// Time Complexity - O(n) Space Complexity - O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while (!q.empty()) {
            lvl++;
            int sz = q.size(), i = 0;
            vector<int> temp(sz);
            while (sz--) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                if (lvl & 1)
                    temp[i++] = t->val;
                else
                    temp[temp.size() - i++ - 1] = t->val;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};