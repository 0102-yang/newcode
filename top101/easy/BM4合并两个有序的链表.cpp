/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
        // 判空。
        if (!pHead1) {
            return pHead2;
        }
        if (!pHead2) {
            return pHead1;
        }

        // 确认新的头节点。
        ListNode* new_head = nullptr;
        if (pHead1->val <= pHead2->val) {
            new_head = pHead1;
            pHead1 = pHead1->next;
        } else {
            new_head = pHead2;
            pHead2 = pHead2->next;
        }
        ListNode* new_tail = new_head;

        // 有序连接节点。
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) {
                new_tail->next = pHead1;
                new_tail = pHead1;
                pHead1 = pHead1->next;
            } else {
                new_tail->next = pHead2;
                new_tail = pHead2;
                pHead2 = pHead2->next;
            }
        }

        // 拼接剩下的节点。
        new_tail->next = pHead1 ? pHead1 : pHead2;
        return new_head;
    }
};