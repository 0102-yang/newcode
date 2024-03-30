#include "../common-header.hpp"

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution1
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param lists ListNode类vector 
     * @return ListNode类
     */
    ListNode* MergeKLists(vector<ListNode*>& lists)
    {
        // write code here
        ListNode* new_head = nullptr;
        ListNode* tail = nullptr;
        while (true) {
            if (ranges::all_of(lists, [](const ListNode* node) { return !node; })) {
                break;
            }

            auto min_node = ranges::min_element(lists, [](const ListNode* l1, const ListNode* l2) {
                if (!l1 && !l2) {
                    return true;
                }
                if (!l1 && l2) {
                    return false;
                }
                if (!l2 && l1) {
                    return true;
                }
                return l1->val < l2->val;
            });
            if (new_head) {
                tail->next = *min_node;
                tail = *min_node;
            } else {
                new_head = *min_node;
                tail = new_head;
            }
            *min_node = (*min_node)->next;
        }
        return new_head;
    }
};

class Solution2
{
public:
    ListNode* MergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) {
            return nullptr;
        }
        return MergeKLists(lists.begin(), lists.end() - 1);
    }

private:
    ListNode* MergeKLists(const vector<ListNode*>::iterator& begin, const vector<ListNode*>::iterator& end)
    {
        if (end == begin) {
            return *begin;
        }
        const auto median = begin + (end - begin) / 2;
        ListNode* left_head = MergeKLists(begin, median);
        ListNode* right_head = MergeKLists(median + 1, end);
        return Merge(left_head, right_head);
    }

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

        return new_head_aux.next;
    }
};