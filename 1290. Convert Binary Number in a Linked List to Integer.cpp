// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// I have taken a particular node and multiplied it by two and added it to the next node. It will mutiply the first
// node with 2 exactly n - 1 time, the 2nd node n - 2 times and so on. This is what we want.
// Time Complexity - O(n), Space Complexity - O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        while (head->next != nullptr) {
            head->next->val += head->val * 2;
            head = head->next;
        }
        return head->val;
    }
};