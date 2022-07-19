// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// What I have done here is that I know if a node don't have left and right pointers then the that node val is the answer
// Otherwise I know if their is a left pointer or a right pointer then we will go in that direction, from each level we can 
// either pick the left val, if it is greater, the right val, or the root val or root val ++ left val or root val + right val
// or root val + left val + right val.
// Time Complexity - O(n) Space Complexity - O(h)
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
    int ans = -1000;
    
    int mxsum(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        int lsum = -1000, rsum = -1000;
        if (root->left)
            lsum = mxsum(root->left);
        if (root->right)
            rsum = mxsum(root->right);
        ans = max(ans, max(root->val + lsum + rsum, max(root->val, max(root->val + lsum, max(root->val + rsum, max(lsum, rsum))))));
        return max(lsum + root->val, max(rsum + root->val, root->val));
    }
    
    int maxPathSum(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        mxsum(root);
        return ans;
    }
};