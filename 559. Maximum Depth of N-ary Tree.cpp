// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// I have written DFS approach here, as BFS approach is quite easy to implement by ourself using depth
// and storing maxDepth as answer.
// Time Complexity - O(n) Space Complexity - O(H)
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
    int ans = 0;
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++)
            depth =  max(depth, maxDepth(root->children[i]));
        return 1 + depth;
    }
};