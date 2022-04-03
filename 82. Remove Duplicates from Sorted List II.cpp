// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// I have kept 3 pointers, one curr, one behind it and one ahead of it. Now the pointer behind curr i.e pcurr points
// to the node which will be unique. I am comparing curr and ncurr(one ahead of curr). If both their values are same then
// I am replacin the ncurr with its next node. Now I have written several cases through which I can give the answer.
// LOL, I have read someones aproach and came to know that I can skip checking this pcurr nullptr part.
// We can create a sentinel node, i.e a dummy node we will return its next pointer.
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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pcurr = nullptr, *curr = head, *ncurr = head->next;
        while (ncurr != nullptr) {
            if (curr->val == ncurr->val) {
                while (ncurr != nullptr && curr->val == ncurr->val) {
                    curr->next = ncurr->next;
                    ncurr = ncurr->next;
                }
                if (ncurr == nullptr)
                    if (pcurr == nullptr)
                        return nullptr;
                    else {
                        pcurr->next = nullptr;
                        return head;
                    }
                if (ncurr->next == nullptr)
                    if (pcurr == nullptr)
                        return ncurr;
                    else {
                        pcurr->next = ncurr;
                        return head;
                    }
                if (ncurr->val == ncurr->next->val) {
                    curr = ncurr;
                    ncurr = ncurr->next;
                }
                else {
                    if (pcurr == nullptr) {
                        pcurr = ncurr;
                        head = pcurr;
                        curr = ncurr->next;
                        ncurr = ncurr->next->next;
                    }
                    else {
                        pcurr->next = ncurr;
                        pcurr = pcurr->next;
                        curr = ncurr->next;
                        ncurr = ncurr->next->next;
                    }
                }
            }
            else {
                if (pcurr == nullptr) {
                    pcurr = curr;
                    head = pcurr;
                    curr = curr->next;
                    ncurr = ncurr->next;
                }
                else {
                    pcurr->next = curr;
                    pcurr = pcurr->next;
                    curr = curr->next;
                    ncurr = ncurr->next;
                }
            }
        }
        return head;
    }
};