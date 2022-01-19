// https://leetcode.com/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Here I again have used Floyd cycle detection algorithm
// It is basically a slow and fast pointer approach.
// Now after checking that a cycle is present in the linked list 
// I have calculated the length of the cycle and then advance one pointer
// by that amount from head and start one from head and move them step by step
// they will now meet at the starting node of the linked list.
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                int cnt = 1;
                while (slow->next != fast)
                    slow = slow->next, cnt++;
                slow = fast = head;
                while (cnt--)
                    fast = fast->next;
                while (slow != fast)
                    slow = slow->next, fast = fast->next;
                return slow;
            }
        }
        return NULL;
    }
};