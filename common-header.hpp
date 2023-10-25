#include <bits/stdc++.h>
using namespace std;

// List node
struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Tree node
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};