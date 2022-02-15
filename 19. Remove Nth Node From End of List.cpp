// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// I have first calculated the total length of the linked list. Then I know, that from which position from start we have to remove
// the next element. Then we cam to one element before the element tot be removed. Then, we pointed it to it's next's next element
// in the linked list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;
        int sz = 1;
        ListNode *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            sz++;
        }
        if (n == sz) {
            return head->next;
        }
        temp = head;
        n = sz - n;
        while (--n) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};

// One pass apporach
// It is not too much different from above approach. What we have done here is that 
// we moved a fast pointer n steps ahead, and a slow pointer n places behind that fast pointer.
// Now if we still haven't encountered that deleting element we will find it soon, or
// the first element needs to be removed.
// Time Complexity - O(n), Space Complexity - O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) 
            fast = fast->next;
        if (!fast) 
            return head->next;
        while (fast->next) 
            fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }