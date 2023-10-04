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
   * @param head ListNode类
   * @return ListNode类
   */
    ListNode* ReverseList(ListNode* head)
    {
        if (!head) {
            return nullptr;
        }

        ListNode* next_node = head->next;
        ListNode* new_next = nullptr;
        head->next = nullptr;

        while (next_node) {
            new_next = next_node->next;
            next_node->next = head;
            head = next_node;
            next_node = new_next;
        }

        return head;
    }
};