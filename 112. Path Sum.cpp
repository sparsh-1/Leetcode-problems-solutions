// https://leetcode.com/problems/path-sum/
// After seeing some solutios, I am thinking what have I done 😢
// I have used current sum and target sum as pointers here, If anyhow I recieve the target sum == current suma and
// it is a leaf node i make the chk tru, which indicates the presence of target sum in tree.
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
    bool chk = false;
    int helper(TreeNode *root, int ts, int cs) {
        if (root == nullptr)
            return 0;
        cs += root->val;
        if (root->left == nullptr && root->right == nullptr && cs == ts) {
            chk = true;
            return 0;
        }
        cs += helper(root->left, ts, cs);
        cs += helper(root->right, ts, cs);
        return 0;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        int ts = 0;
        helper(root, targetSum, ts);
        return chk;
    }
};


// A very elegant form of code
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (!root->left && !root->right && targetSum == root->val) return true;
        return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
    }
};