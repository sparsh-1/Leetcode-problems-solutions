// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// I have stored the paths of the node from root to that node itself. Now root will be the ancestor of every node.
// I will just traverse both the part simultaneously until I get a different path in the binary tree.
// Time Complexity - O(n) Space Complexity - O(h)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> a, b;
    
    bool helper(TreeNode *root, TreeNode *fin, vector<TreeNode*> &vec) {
        if (root == nullptr)
            return 0;
        vec.push_back(root);
        if (vec.back() == fin)
            return 1;
        if (helper(root->left, fin, vec) || helper(root->right, fin, vec))
            return 1;
        vec.pop_back();
        return 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, a);
        helper(root, q, b);
        int i = 0;
        while (i < min(a.size(), b.size()) && a[i] == b[i]) {
            i++;
        }
        return a[i - 1];
    }
};


// In the above approach I am using 2 * space and 2 * time, but here in a single traversal I am 
// giving the answer. What I am doing here is that if for a node it is the node to be found, I will return it
// Now for some other node if it is getting nullptr it means that it don't have a path to the node we are going
// to find and if it have 1 nullptr coming and 1 pointer to path coming that means that it have a path to 1 node that have to find
// i.e.e it is atleast ancestor of 1 node. If at any node both the nodes are not giving nullptr then it means
// that that node is the ancestor of both nodes and I will return that node only.
// Time Complexity - O(N) Space Complexity - O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;
        return root;
    }
};