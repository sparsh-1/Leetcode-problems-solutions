// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// I am keeping the max element I have encountered till now, and then using the help of backtracking to reset the previous max element.
// As soon the node val is greater than or equalt to current end element at arr, I have to increment the answer.
// Time Complexity - O(n) Space Complexity - O(n) or O(h)
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
    int ans = 0;
    void solve(TreeNode *root, vector<int> &arr) {
        if (root == nullptr)
            return;
        if (arr.size() == 0)
            arr.push_back(root->val);
        else
            arr.push_back(max(arr.back(), root->val));
        if (root->val >= arr.back())
            ans++;
        if (root->left)
            solve(root->left, arr);
        if (root->right)
            solve(root->right, arr);
        arr.pop_back();
    }
    int goodNodes(TreeNode* root) {
        vector<int> temp;
        solve(root, temp);
        return ans;
    }
};

// Here I have used only the maximum element instead of the array as I know that the maximum element till that node is what.
// Now if I move backward, I have the previous maxValue inside the previos maxValue which was initially there.
// Time Complexity - O(n) Space Complexity - O(n) or O(h)
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
    int ans = 0;
    void solve(TreeNode *root, int maxVal) {
        if (root == nullptr)
            return;
        if (root->val >= maxVal) {
            ans++;
            maxVal = root->val;
        }
        if (root->left)
            solve(root->left, maxVal);
        if (root->right)
            solve(root->right, maxVal);
    }
    int goodNodes(TreeNode* root) {
        solve(root, -1e5);
        return ans;
    }
};