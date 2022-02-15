// https://leetcode.com/problems/delete-node-in-a-linked-list/
// The question statement is quite ambiguous and confusing, so for tacklinkg this problem, we need to copy 
// the next node to previous node and point the second last node to nullptr.
// Time Complpexity - O(n), Space Complexity - O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next->next != nullptr) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = nullptr;
    }
};

// Second Approach
// Saw someone solution ad laughed that this is much more intutive solution than mine
// Here we just copied the value of next node and then pointed that node to its next's next node.
// Time Complexity - O(1), Space Complexity - O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};