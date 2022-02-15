// https://leetcode.com/problems/middle-of-the-linked-list/
// I only have used one (1) pass approach here using slow and fast pointers. If there are atleast 2 nodes ahead of fast pointer
// then we haven't reached middle element yet. If there is only one node left then we have to return the second middle node as 
// the ll is even in size. If there are no nodes ahead in linked list then we have to return the slow pointer itself.
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            else if (fast->next != nullptr)
                return slow->next;
            else
                return slow;
        }
        return slow;
    }
};