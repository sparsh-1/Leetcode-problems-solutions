// https://leetcode.com/problems/symmetric-tree/
// Here I know, that for every right node of a particular node in left subtree sofe left node of a particular node in right subtree must be equal.
// I have use the same approach using BFS and stacks for the first half of the queue element to compare the above logic.
// But I think I have written too many conditions which made the code complicated.
// Time Complexity - O(2*N) Space Complexity - O(N)
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
    
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        else if (root->left == nullptr)
            return false;
        else if (root->right == nullptr)
            return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            int sz = q.size();
            if (sz % 2 == 0) {
                stack<TreeNode*> temp;
                int sz2 = sz / 2;
                while (sz2--) {
                    temp.push(q.front());
                    if (q.front()->left != nullptr)
                        q.push(q.front()->left);
                    if (q.front()->right != nullptr)
                        q.push(q.front()->right);
                    q.pop();
                }
                sz2 = 0;
                while (sz2 != sz / 2) {
                    if ((temp.top()->right == nullptr && q.front()->left == nullptr) || (temp.top()->left == nullptr && q.front()->right == nullptr)) {
                        if (temp.top()->val == q.front()->val) {
                            if (temp.top()->right == nullptr && q.front()->left == nullptr && temp.top()->left == nullptr && q.front()->right == nullptr) {}
                            else if (temp.top()->right == nullptr && q.front()->left == nullptr) {
                                q.push(q.front()->right);
                            }
                            else {
                                q.push(q.front()->left);
                            }
                            sz2++;
                            q.pop();
                            temp.pop();
                            continue;
                        }
                        else
                            return false;
                    }
                    if (temp.top()->right && q.front()->left && temp.top()->val == q.front()->val) {
                        q.push(q.front()->left);
                    }
                    else
                        return false;
                    if (temp.top()->left && q.front()->right && temp.top()->val == q.front()->val) {
                        q.push(q.front()->right);
                    }
                    else
                        return false;
                    sz2++;
                    q.pop();
                    temp.pop();
                }
            }
            else
                return false;
        }
        return true;
    }
};


// Really Simple and Iterative Approach
// Time Complexity - O(N) Space Complexity - O(h)
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
    bool helper(TreeNode* left, TreeNode*right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};