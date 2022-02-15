// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// We are given up a sorted linked list, this means that same elements will occur consecutively. So if we see any 2 consecutive
// element, we will point the first occurence to its seconds next occurence. We will repeat this process till we reach the end.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *temp = head;
        while (temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};