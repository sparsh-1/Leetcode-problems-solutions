// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// What I have done here is I have used backtracking, If I can descend to any level below, I can increase the size by 1
// but if I cant descend any further i store the max answer and decrease the height by 1. The max height + 1 will be the answer.
// Time Complexity - O(n) Space Complexity - (log(n)) [Average] O(n) [ When tree is skew]
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
    int ans = 0, md = 0;
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return md;
        if (root->left != nullptr) {
            ans++;
            maxDepth(root->left);
        }
        if (root->right != nullptr) {
            ans++;
            maxDepth(root->right);
        }
        md = max(ans, md);
        ans--;
        return md + 1;
    }
};


// Another much more beautiful looking solution
// Time Complexity - O(N) Space Complexity - (log(n)) [Average] O(n) [ When tree is skew]
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};