// https://leetcode.com/problems/binary-tree-right-side-view/
// I have used BFS (level order traversal) here to traverse the tree, For each level the last node will be visible 
// in the right side view of the binary tree. So I just kept that right node in ans.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz != 1) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                sz--;
            }
            TreeNode *temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return ans;
    }
};


// Recursive - DFS Approach
// As in BFS, it is mostly always possible that the size is maximum n / 2 or n / 4 i.e. O(n)
// To overcome it we can use DFS. The size can even go to O(N) in DFS when the tree came out to be skew, but generally trees are not skew
// Also the DFS approach looks more intutive.
// If at any point ans size equals level this means that it is the rightmost node on that particular level.
// So i pushed it into ans.
// Time Complexity - O(N) Space Complexity - O(N)
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
    void helper(TreeNode *root, vector<int> &ans, int lvl) {
        if (root == nullptr)
            return;
        if (ans.size() == lvl) ans.push_back(root->val);
        helper(root->right, ans, lvl + 1);
        helper(root->left, ans, lvl + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        helper(root, ans, 0);
        return ans;
    }
};