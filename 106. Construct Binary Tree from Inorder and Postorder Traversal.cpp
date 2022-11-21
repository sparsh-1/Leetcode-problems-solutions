// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// I have just used the propery of inorder and postorder and constructed the tree as in postorder, the left part of root is left subtree
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(postorder.back());
        int i = 0;
        for (i = 0; i < inorder.size(); i++)
            if (inorder[i] == postorder.back())
                break;
        vector<int> ino(inorder.begin(), inorder.begin() + i);
        vector<int> ino2(inorder.begin() + i + 1, inorder.end());
        vector<int> po1(postorder.begin(), postorder.begin() + i);
        vector<int> po2(postorder.begin() + i, postorder.end() - 1);
        root->right = buildTree(ino2, po2);
        root->left = buildTree(ino, po1);
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return answer(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
    }
    
    TreeNode *answer(vector<int> &inorder, int start, int end, vector<int> &postorder, int pstart, int pend, map<int, int> &mp) {
        if (start > end || pstart > pend)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[pend]);
        int proot = mp[root->val];
        root->right = answer(inorder, proot + 1, end, postorder, pstart + proot - start, pend - 1, mp);
        root->left = answer(inorder, start, proot - 1, postorder, pstart, proot + pstart - 1 - start, mp);
        return root;
    }
};