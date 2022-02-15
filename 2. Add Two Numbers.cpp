// https://leetcode.com/problems/add-two-numbers/
// As the numbers are given as reverded list, we can easily add their starting indexex in ones, tens, hundreds, ... manner
// So we will add the number and if we enconter any number sum exceeding 10, then we will carry forward it to the next node.
// We will do this process so on either till both lists gets vanished or one list get vanished. If both list get vanished we return the answer.
// Otherwise we will do the same process with the greater list and then append it to the answer list checking that all numbers
// are single digit only.
// Also sorry, as I have made my code too long, it can be made small by doing some tweaks.
// Time Complexity - O(n) [n is size of larger nuumber], Space Complexity - O(n) [We can do the same in O(1), if we modify the original list]
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
    ListNode* reverse(ListNode *l) {
        return l;
        if (l == nullptr || l->next == nullptr)
            return l;
        ListNode *back = nullptr, *front = l, *nfront = l->next;
        while (nfront != nullptr) {
            cout << front->val << " ";
            front->next = back;
            back = front;
            front = nfront;
            nfront = nfront->next;
        }
        cout << front->val;
        front->next = back;
        return front;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode;
        ListNode *sans = ans;
        if (l1 == nullptr)
            return reverse(l2);
        if (l2 == nullptr)
            return reverse(l1);
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val + l2->val <= 9) {
                ListNode *temp = new ListNode(l1->val + l2->val);
                cout << temp->val << " ";
                if (sans == nullptr) {
                    sans = temp;
                    ans= sans;
                }
                else
                    sans->next = temp;
                sans = sans->next;
            }
            else {
                ListNode *temp = new ListNode((l1->val + l2->val) % 10);
                if (sans == nullptr) {
                    sans = temp;
                    ans = sans;
                }
                else
                    sans->next = temp;
                sans = sans->next;
                if (l1->next != nullptr)
                    l1->next->val++;
                else if (l2->next != nullptr)
                    l2->next->val++;
                else {
                    ListNode *temp = new ListNode(1);
                    sans->next = temp;
                    return reverse(ans->next);
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            if (l1->val <= 9) {
                sans->next = l1;
                return reverse(ans->next);
            }
            else {
                ListNode *temp = new ListNode(l1->val % 10);
                sans->next = temp;
                sans = sans->next;
                if (l1->next == nullptr) {
                    ListNode *temp = new ListNode(1);
                    sans->next = temp;
                    return reverse(ans->next);
                }
                l1->next->val++;
            }
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            if (l2->val <= 9) {
                sans->next = l2;
                return reverse(ans->next);
            }
            else {
                ListNode *temp = new ListNode(l2->val % 10);
                sans->next = temp;
                sans = sans->next;
                if (l2->next == nullptr) {
                    ListNode *temp = new ListNode(1);
                    sans->next = temp;
                    return reverse(ans->next);
                }
                l2->next->val++;
            }
            l2 = l2->next;
        }
        return reverse(ans->next);
    }
};