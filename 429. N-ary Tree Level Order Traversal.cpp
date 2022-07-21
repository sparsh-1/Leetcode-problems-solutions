// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// I have just used the simple BFS using queue.
// Time Complexity - O(n) Space Complexity - O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int sz = q.size();
            while (sz--) {
                Node *t = q.front();
                q.pop();
                temp.push_back(t->val);
                for (int i = 0; i < t->children.size(); i++)
                    q.push(t->children[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


// Intresting DFS solution to perform BFS on leetcode discuss
// Time Complexity - O(N) Space Complexity - O(H)
class Solution { // 16 ms, faster than 98.53%
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return ans;
    }
    void dfs(Node* root, int level) {
        if (root == nullptr) return;
        if (level == ans.size()) ans.emplace_back(); // Need more level -> Add new level
        ans[level].push_back(root->val);
        for (Node* child : root->children)
            dfs(child, level + 1);
    }
};