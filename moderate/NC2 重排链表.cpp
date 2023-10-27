#include "../common-header.hpp"

// 先将链表分成两半，然后逆序后半部分链表，最后组合链表。

// Time complexity: O(n), Space complexity: O(n)
class MySolution1
{
public:
    void reorderList(ListNode* head)
    {
        vector<ListNode*> node_addresses;
        auto itr = head;
        while (itr) {
            node_addresses.push_back(itr);
            itr = itr->next;
        }

        int half_size = node_addresses.size() / 2;
        vector<ListNode*> right_half_node_addresses(node_addresses.begin() + half_size, node_addresses.end());
        reverse(right_half_node_addresses.begin(), right_half_node_addresses.end());

        for (int i = 0; i < half_size; i++) {
            if (i != 0) {
                right_half_node_addresses[i - 1]->next = node_addresses[i];
            }
            node_addresses[i]->next = right_half_node_addresses[i];
            if (i == half_size - 1) {
                if (node_addresses.size() % 2 == 0) {
                    right_half_node_addresses[i]->next = nullptr;
                } else {
                    right_half_node_addresses[i]->next = right_half_node_addresses[i + 1];
                    right_half_node_addresses[i + 1]->next = nullptr;
                }
            }
        }
    }
};

// Time complexity: O(n), Space complexity: O(1)
class MySolution2
{
public:
    void reorderList(ListNode* head)
    {
        if (!head) {
            return;
        }

        const int length = GetListLength(head);

        // Get right head
        ListNode* right_head_prev = nullptr;
        ListNode* right_head = head;
        int half_length = length / 2;
        for (int i = 0; i < half_length; i++) {
            right_head_prev = right_head;
            right_head = right_head->next;
        }
        if (length % 2 != 0) {
            right_head_prev = right_head;
            right_head = right_head->next;
        }
        right_head_prev->next = right_head = ReverseList(right_head);

        // Reorder
        ListNode* left = head;
        ListNode* right = right_head;
        for (int i = 0; i < half_length; i++) {
            head = head->next;
            right_head = right_head->next;

            left->next = right;
            right->next = head;
            if (i == half_length - 1 && length % 2 == 0) {
                right->next = nullptr;
            }
        }
    }

private:
    ListNode* ReverseList(ListNode* head)
    {
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

    int GetListLength(ListNode* head)
    {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
};