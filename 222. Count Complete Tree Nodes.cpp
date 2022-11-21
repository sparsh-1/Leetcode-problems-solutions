// https://leetcode.com/problems/count-complete-tree-nodes/
// Just done a simple BFS and counted number of nodes
// time Complexity - O(n) Space Complexity - O(n)
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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int num = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            num++;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return num;
    }
};


// Second Approach
// As we know that it is a full binary tree, we can utilise its property
// If left and right height of a tree is equa, then nodes in that tree are 2^h - 1, if not I compute 1 + left node height + right node height
// Time Comlexity - O((logn)^2) // Log n for travelling height logn and ogn for finding height of tree at each node.
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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lh = left(root), rh = right(root);
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int left(TreeNode *root) {
        int ht = 1;
        while (root->left)
            root = root->left, ht++;
        return ht;
    }
    
    int right(TreeNode *root) {
        int ht = 1;
        while (root->right)
            root = root->right, ht++;
        return ht;
    }
};