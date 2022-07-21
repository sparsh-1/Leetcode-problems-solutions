// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// I have done simple postorder traversal here
// Time Complexity - O(n) Space Complexity - O(N)
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
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return ans;
        for (int i = 0; i < root->children.size(); i++)
            postorder(root->children[i]);
        ans.push_back(root->val);
        return ans;
    }
};


// Iterative solution - 2 stacks
// Time Complexity - O(N) Space Complexity - O(N)
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
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return ans;
        stack<Node*> s;
        stack<int> val;
        s.push(root);
        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();
            val.push(temp->val);
            for (int i = 0; i < temp->children.size(); i++)
                s.push(temp->children[i]);
        }
        while (!val.empty()) {
            ans.push_back(val.top());
            val.pop();
        }
        return ans;
    }
};