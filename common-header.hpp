#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// List node
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(const int x) : val(x), next(nullptr) {}
};

// Tree node
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};