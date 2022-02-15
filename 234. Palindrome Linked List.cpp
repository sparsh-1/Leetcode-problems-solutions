// https://leetcode.com/problems/palindrome-linked-list/
// Since we have to check for palindrome sequence, I have reversed the last half of the sequence.
// For finding the middle element I have used slow and fast pointer technique. Then I reversed the next half and compared
// the element from head and mid. If at any point the elements are unequal I will return false, otherwise true.
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
    ListNode* reverse(ListNode *head) {
        ListNode *bprev = nullptr, *prev = head, *next = head->next;
        while (next != nullptr) {
            prev->next = bprev;
            bprev = prev;
            prev = next;
            next = next->next;
        }
        prev->next = bprev;
        head = prev;
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while (slow != nullptr) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};