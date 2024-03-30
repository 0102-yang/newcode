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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead1 ListNode类
     * @param pHead2 ListNode类
     * @return ListNode类
     */
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