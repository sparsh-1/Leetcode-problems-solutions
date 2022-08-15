// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// What I have done here is that First I have created a hashmap in which I have stored parent nodes of each and every node
// (as there are unique values i used int, TreeNode*). Now I have inserted a target node inside the queue. And after that I will check its parent, its left and its right node
// if any of them is present then i push it inside queue again and will increase the distance. If at any point the distance reached k
// I will break and the elements present inside the queue are the elements that are at k distance from the target node.
// Time Complexity - O(Number of Nodes) * mapComplexity Space Complexity - O(Number of Nodes)
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0)
            return {target->val};
        map<int, TreeNode *> parentMapping;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
                parentMapping[temp->left->val] = temp;
            }
            if (temp->right) {
                q.push(temp->right);
                parentMapping[temp->right->val] = temp;
            }
        }
        vector<int> ans;
        q.push(target);
        vector<bool> visited(501, false);
        visited[target->val] = true;
        int distance = 0;
        while (distance != k && !q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode *temp = q.front();
                q.pop();
                if (parentMapping.find(temp->val) != parentMapping.end() && visited[parentMapping[temp->val]->val] == false) {
                    q.push(parentMapping[temp->val]);
                    visited[parentMapping[temp->val]->val] = true;
                }
                if (temp->left && visited[temp->left->val] == false) {
                    q.push(temp->left);
                    visited[temp->left->val] = true;
                }
                if (temp->right && visited[temp->right->val] == false) {
                    q.push(temp->right);
                    visited[temp->right->val] = true;
                }
            }
            distance++;
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};