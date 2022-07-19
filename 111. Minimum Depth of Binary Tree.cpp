// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// I have used basic recursion here i.e. DFS for seeing if shorter height is available or not, if it is available then I take that height
// else if only 1 branch is available, it is mandatory to choose that branch. Here I can see I will definitely travel all nodes and till
// maximum depth of the tree.
// Time Complexity - O(N) Space Complexity - O(max(height of tree))
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left != nullptr && root->right != nullptr)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        else if (root->left != nullptr)
            return 1 + minDepth(root->left);
        return 1 + minDepth(root->right);
    }
};


// BFS Approach
// It is much more efficient than DFS, because in BFS  I travel all the levels, but in BFS if anywhere I found a leaf node, then it
// is sure that it will be the shortest depth and I don't need to travel further.
// Time Complexity - O(n) Space Complexity - O(N)
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth++;
            int sz = q.size();
            while (sz--) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left == nullptr && temp->right == nullptr)
                    return depth;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return -1;
    }
};