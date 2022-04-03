// https://leetcode.com/problems/merge-two-sorted-lists/
// What I have done here is that i have first assigned the minimum element to head,
// and after that  assigned the elements in ascending order 1 by 1, until a single list gets exhausted
// After that i assigned the non empty list to the head pointers last node.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *head;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
        ListNode *re = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
                head = head->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;
                head = head->next;
            }
        }
        if (list1 != nullptr)
            head->next = list1;
        if (list2 != nullptr)
            head->next = list2;
        return re;
    }
};