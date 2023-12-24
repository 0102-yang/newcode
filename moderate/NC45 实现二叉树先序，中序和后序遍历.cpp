#include "../common-header.hpp"

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> threeOrders(TreeNode* root)
    {
        vector<vector<int>> orders(3);
        preOrder(orders[0], root);
        inOrder(orders[1], root);
        postOrder(orders[2], root);
        return orders;
    }

private:
    void preOrder(vector<int>& order, const TreeNode* root)
    {
        if (!root) {
            return;
        }

        order.push_back(root->val);
        preOrder(order, root->left);
        preOrder(order, root->right);
    }

    void inOrder(vector<int>& order, const TreeNode* root)
    {
        if (!root) {
            return;
        }

        inOrder(order, root->left);
        order.push_back(root->val);
        inOrder(order, root->right);
    }

    void postOrder(vector<int>& order, const TreeNode* root)
    {
        if (!root) {
            return;
        }

        postOrder(order, root->left);
        postOrder(order, root->right);
        order.push_back(root->val);
    }
};