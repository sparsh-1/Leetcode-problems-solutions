// https://leetcode.com/problems/balanced-binary-tree/
// I have applied a brute force approach here, I go to every node and see if their left node and right node have 
// a height difference less than equal to 1 or not, if it is then continue, otherwise I return false;
// I also seef is a left pointer is null then if rights right or left exist then again height difference goes to greater than 1 and
// I return false;
// Time Complexity - O(N^2) Space Complexity - O(N)
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
    int maxheight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(maxheight(root->left), maxheight(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left == nullptr && temp->right == nullptr)
                    continue;
                else if (temp->left != nullptr && temp->right != nullptr) {
                    if (abs(maxheight(temp->left) - maxheight(temp->right)) > 1)
                        return false;
                    q.push(temp->left);
                    q.push(temp->right);
                }
                else if (temp->left != nullptr) {
                    if (temp->left->left != nullptr || temp->left->right != nullptr)
                        return false;
                    q.push(temp->left);
                }
                else {
                    if (temp->right->left != nullptr || temp->right->right != nullptr)
                        return false;
                    q.push(temp->right);
                }
            }
        }
        return 1;
    }
};


// A solution that checks at every step the height of the tree for the largest tree i.e for the orr node
// What happens here is if any subtree have height difference more than 1 then it returns height as -1, and our function returns -1
// stating that the tree is indeed not balanced.
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
    int maxheight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lh = maxheight(root->left);
        int rh = maxheight(root->right);
        if (lh == -1 || rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        return maxheight(root) == -1? false: true;
    }
};