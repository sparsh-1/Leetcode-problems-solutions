// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// I have considered the root node at the origin of 2-D plane. Now for every left node it have I decreased the 
// X cordinate by 1 and for every right node I increase the x coordinate by 1. Now, for the depth part, I just keep on increasing
// the height of the node by increasing the y coordinate. I have used a (map of int, map of int and vector<int>) the first int is storing the
// value of x coordinate i.e. nodes lying on that x line, the next int stores the y coordinate i.e (x, y)
// for each x, y if more than 1 nodes occur at same point I keep it at same vector and sort it before displaying the answer
// Instead of using I can use multiset too, which will keep sorted elements only and further reduces time complexity
// Also I have used level order traversal here, we can use any traversal inorder, preorder or postorder too.
// Time Complexity - O(N2) Space Complexity - O(N)
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto it = q.front();
                q.pop();
                mp[it.second.first][it.second.second].push_back(it.first->val);
                if (it.first->left)
                    q.push({it.first->left, {it.second.first - 1, it.second.second + 1}});
                if (it.first->right)
                    q.push({it.first->right, {it.second.first + 1, it.second.second + 1}});
            }
        }
        for (auto i: mp) {
            vector<int> temp;
            for (auto j: i.second) {
                if (j.second.size() > 1)
                    sort(j.second.begin(), j.second.end());
                for (auto k: j.second)
                    temp.push_back(k);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};