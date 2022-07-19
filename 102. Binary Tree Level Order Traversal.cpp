// https://leetcode.com/problems/binary-tree-level-order-traversal/
// I have used queue dta structure to perform level order traversal of a tree. I know that if a left node is occuring I have to take it next
// after roo, if right is occuring I have to take it after that left. So, I just place the value of root and then
// push left and right in queue accordingly. The size of the current queue denotes the number of nodes in that particular
// level.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int sz = q.size();
            while (sz--) {
                temp.push_back(q.front()->val);
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};