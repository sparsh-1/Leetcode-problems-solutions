// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// I am doing level order traversal and storing each value inside square brackets. If i encounter any null value I put 
// underscore _. For deserializing I followed the same approach, for every node if i found any element i put left and right element
// if they exist otherwise they are null. If any null node is encountered it is skipped.
// Time Complexity - O(n) Space Complexity - O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == nullptr)
                ans += '_';
            else {
                q.push(temp->left);
                q.push(temp->right);
                ans += '[' + to_string(temp->val) + ']';
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *ans;
        if (data.size() == 0)
            return nullptr;
        int i = 0;
        if (data[i] == '[') {
            i++;
            string temp = "";
            while (data[i] != ']')
                temp += data[i++];
            ans = new TreeNode(stoi(temp));
            i++;
        }
        queue<TreeNode*> q;
        q.push(ans);
        while (i < data.size() && !q.empty()) {
            TreeNode *te = q.front();
            q.pop();
            if (te != nullptr) {
                if (data[i] == '[') {
                    i++;
                    string temp = "";
                    while (data[i] != ']')
                        temp += data[i++];
                    te->left = new TreeNode(stoi(temp));
                    q.push(te->left);
                    i++;
                }
                else
                    i++;
                if (data[i] == '[') {
                    i++;
                    string temp = "";
                    while (data[i] != ']')
                        temp += data[i++];
                    te->right = new TreeNode(stoi(temp));
                    q.push(te->right);
                    i++;
                }
                else
                    i++;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));