#include "../common-header.hpp"

/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode new_head_aux(0);
        ListNode* tail = &new_head_aux;

        while (pHead1 || pHead2) {
            if (pHead1 && pHead2) {
                ListNode* tmp;
                if (pHead1->val < pHead2->val) {
                    tmp = pHead1;
                    pHead1 = pHead1->next;
                } else {
                    tmp = pHead2;
                    pHead2 = pHead2->next;
                }
                tail->next = tmp;
                tail = tmp;
            } else if (pHead1) {
                tail->next = pHead1;
                break;
            } else {
                tail->next = pHead2;
                break;
            }
        }

        ListNode* new_head = new_head_aux.next;
        return new_head;
    }
};