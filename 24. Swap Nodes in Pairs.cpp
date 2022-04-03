// https://leetcode.com/problems/swap-nodes-in-pairs/
// I have added a dummy node i.e sentinel node in beginning and just interchanging he node pairwise.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *temp = new ListNode(0, head);
        head = temp;
        ListNode *pcurr = head->next, *curr = head->next->next, *ncurr = head->next->next->next;
        while (ncurr != nullptr) {
            pcurr->next = curr->next;
            curr->next = pcurr;
            temp->next = curr;
            temp = temp->next->next;
            pcurr = ncurr;
            curr = pcurr->next;
            if (curr == nullptr)
                return head->next;
            ncurr = curr->next;
        }
        pcurr->next = curr->next;
        curr->next = pcurr;
        temp->next = curr;
        return head->next;
    }
};