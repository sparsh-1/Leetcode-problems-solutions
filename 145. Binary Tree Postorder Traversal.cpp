// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Just normal recursive code left->right->root;
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
    vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return ans;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};


// Iterative solution
// This solution uses 2 stacks 1 for storing the values and 1 for storing the pointers. wherever if i found a left and right pointer I know that root will be printed at end so 
// I add root in value stack first and right thereafter as it is going to be printed 2nd and the left one at first place.
// Now I traverse all the right nodes first and if I encounter no right i trave left.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        stack<int> val;
        while (!s.empty()) {
            TreeNode *temp = s.top();
            s.pop();
            val.push(temp->val);
            if (temp->left != nullptr)
                s.push(temp->left);
            if (temp->right != nullptr)
                s.push(temp->right);
        }
        while (!val.empty()) {
            ans.push_back(val.top());
            val.pop();
        }
        return ans;
    }
};


// Iterative Solution
// It is approximately same as above, instead it uses only 1 stack instead of 2, but have a time complexity of
// O(2*n) == O(n) because of the inner while loop. I just insert elements in the stack and then check whether it was a right 
// child of the root or not, if yes, then I know i have to print right child then the root, otherwise, I have to traverse
// to the right part of that node.
// Time Complexity - O(N) Space Complexity - O(N)
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while (cur != nullptr || !s.empty()) {
            if (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode *temp = s.top()->right;
                if (temp == nullptr) {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while (!s.empty() && temp == s.top()->right) {
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    cur = temp;
            }
        }
        return ans;
    }
};