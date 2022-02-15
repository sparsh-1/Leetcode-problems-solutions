// https://leetcode.com/problems/remove-linked-list-elements/
// I have checked whether the head should not equalt to val. Then as soon as i encounter any node where the val is present
// i point the previous node to its next's next node.
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val)
            head = head->next;
        if (head == nullptr)
            return head;
        ListNode *temp = head;
        while (temp->next != nullptr) {
            if (temp->next->val == val) 
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        if (temp == nullptr)
            return head;
        if (temp->val == val)
            temp = nullptr;
        return head;
    }
};