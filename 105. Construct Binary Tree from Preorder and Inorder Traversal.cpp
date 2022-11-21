// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// I have just used the propery of inorder and preorder and constructed the tree as in inorder, the left part of root is left subtree
// and right part is right subtree
// Time Complexity - O(n^2) Space Complexity - O(n)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        int i;
        for (i = 0; i < inorder.size(); i++)
            if (inorder[i] == preorder[0])
                break;
        vector<int> ino(inorder.begin(), inorder.begin() + i);
        vector<int> ino2(inorder.begin() + i + 1, inorder.end());
        vector<int> pre(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> pre2(preorder.begin() + i + 1, preorder.end());
        root->left = buildTree(pre, ino);
        root->right = buildTree(pre2, ino2);
        return root;
    }
};


// Second Approach
// Same as above approach, but just used map to stop for loop every time
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for (int i = 0; i < preorder.size(); i++)
            inMap[inorder[i]] = i;
        return buildRoot(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }
    
    TreeNode *buildRoot(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        root->left = buildRoot(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildRoot(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};