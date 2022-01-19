// https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// This is a naive approach in which I stored the address of each node and check if that
// node address occurs twice.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> addr;
        while (head != NULL) {
            if (addr.find(head) == addr.end()) {
                addr.insert(head);
                head = head->next;
            }
            else
                return 1;
        }
        return 0;
    }
};

// We can also use Floyd's cycle detection algorithm in linked list using slow and fast pointers
// It is basically if two pointers are in a loop, one is moving slow and one is moving fast
// no matter what they will meet at some point of time.
// Consider it as two runners running on a circular race track with different speeds will definitely
// meet.
// Time Complexity - O(n), Space Complexity - O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = slow;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return 1;
        }
        return 0;
    }
};