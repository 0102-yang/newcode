#include "../common-header.hpp"

/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution1
{
public:
    /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param head ListNode类
   * @return ListNode类
   */
    ListNode* ReverseList(ListNode* head)
    {
        if (!head) {
            return nullptr;
        }

        ListNode* next_node = head->next;
        ListNode* new_next_node = nullptr;
        head->next = nullptr;

        while (next_node) {
            new_next_node = next_node->next;
            next_node->next = head;
            head = next_node;
            next_node = new_next_node;
        }

        return head;
    }
};

class Solution2
{
public:
    /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param head ListNode类
   * @return ListNode类
   */
    ListNode* ReverseList(ListNode* head)
    {
        ListNode* new_head = nullptr;

        while (head) {
            ListNode* tmp = head->next;
            head->next = new_head;
            new_head = head;
            head = tmp;
        }

        return new_head;
    }
};