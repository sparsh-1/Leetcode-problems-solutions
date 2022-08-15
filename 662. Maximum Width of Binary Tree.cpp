// https://leetcode.com/problems/maximum-width-of-binary-tree/
// I have written this very naive brute force approach, which got me tle 😅, but still let me explain my naive approach
// I just traversed the tree in level order traversal. Whenever I reach next level I traverse the queue, if I encounter any nullptr
// (yes I have added nullptrs too) I see if any of the left node is there or not, if it is there, then it might contribute to the length
// otherwise it won't contribute. Then, whenever I encounter right node I calculate the current size and add it to the max answer.
// But this gave me TLE.
// Time Complexity - O(2^n) Space Complexity - O(2^n)
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        while (!q.empty()) {
            int sz = q.size(), tsz = 0;
            bool left = false, right = false;
            while (sz--) {
                TreeNode *temp = q.front();
                q.pop();
                if (left)
                    tsz++;
                if (temp == nullptr) {
                    if (left) {
                        q.push(nullptr);
                        q.push(nullptr);
                    }
                    continue;
                }
                else {
                    if (left == false) {
                        left = true;
                        tsz = 1;
                    }
                    else {
                        right = true;
                        ans = max(ans, tsz);
                    }
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};


// Iterative Solution
// I have used the propert that a parent have a child 2 * i and 2 * i + 1, Now, the maximum nodes lying etween leftest and rightest nodes will be the absolute difference between 
// both the numbers.
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long>> q;
        q.push({root, 0});
        unsigned long ans = 1;
        while (!q.empty()) {
            unsigned long sz = q.size(), st = -1;
            bool left = false;
            while (sz--) {
                auto temp = q.front();
                q.pop();
                if (temp.first->left) {
                    if (left)
                        ans = max(ans, temp.second - st + 1);
                    else {
                        left = true;
                        st = temp.second;
                    }
                    q.push({temp.first->left, 2 * temp.second + 1});
                }
                else {
                    if (left)
                        ans = max(ans, temp.second - st + 1);
                    else {
                        left = true;
                        st = temp.second;
                    }
                }
                if (temp.first->right) {
                    if (left)
                        ans = max(ans, temp.second - st + 1);
                    else {
                        left = true;
                        st = temp.second;
                    }
                    q.push({temp.first->right, 2 * temp.second + 2});
                }
                else {
                    if (left)
                        ans = max(ans, temp.second - st + 1);
                    else {
                        left = true;
                        st = temp.second;
                    }
                }
            }
        }
        return ans;
    }
};