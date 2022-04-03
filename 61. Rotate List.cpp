// https://leetcode.com/problems/rotate-list/
// I have just traveled n - k - 1 steps ahead (n is size of linked list). Then the next pointer must be nullptr as it will be end.
// And its next will become the new head and original end will point to the original head.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int sz = 0;
        ListNode *temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            sz++;
        }
        k = sz - k % sz;
        if (k == sz)
            return head;
        temp = head;
        while (--k)
            temp = temp->next;
        ListNode *tmp = temp->next, *hd = head;
        head = temp->next;
        temp->next = nullptr;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = hd;
        return head;
    }
};