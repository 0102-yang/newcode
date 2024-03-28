#include "../common-header.hpp"

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

// Best Solution
class BestSolution
{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* node1 = pHead1;
        const ListNode* node2 = pHead2;
        while (node1 != node2) {
            node1 = !node1 ? pHead2 : node1->next;
            node2 = !node2 ? pHead1 : node2->next;
        }
        return node1;
    }
};

// My Solution
class MySolution
{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1 || !pHead2) {
            return nullptr;
        }

        const int length1 = GetListLength(pHead1);
        const int length2 = GetListLength(pHead2);
        const int steps_to_move = abs(length1 - length2);
        for (int i = 0; i < steps_to_move; i++) {
            if (length1 > length2) {
                pHead1 = pHead1->next;
            } else {
                pHead2 = pHead2->next;
            }
        }

        while (pHead1) {
            if (pHead1 == pHead2) {
                return pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }

        return nullptr;
    }

private:
    int GetListLength(ListNode* head)
    {
        int length = 0;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }
};