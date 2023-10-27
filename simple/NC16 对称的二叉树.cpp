#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return bool布尔型
     */
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot) {
            return true;
        }

        return equal(pRoot->left, pRoot->right);
    }

private:
    bool equal(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2) {
            return true;
        }
        if (!t1 || !t2 || t1->val != t2->val) {
            return false;
        }
        return equal(t1->left, t2->right) && equal(t1->right, t2->left);
    }
};