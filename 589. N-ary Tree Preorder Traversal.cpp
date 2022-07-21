// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// I have done recursive travel here - Simple preordr
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
    vector<int> ans;
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return ans;
        ans.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
            preorder(root->children[i]);
        return ans;
    }
};


// Iterative solution
// Simple Iterative implementation
// Time Complexity - O(n) Space Complexity -O(n)
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
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            for (int i = temp->children.size() - 1; i >= 0; i--)
                s.push(temp->children[i]);
        }
        return ans;
    }
};