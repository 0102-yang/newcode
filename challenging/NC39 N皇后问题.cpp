#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 the n
     * @return int整型
     */
    int Nqueen(int n)
    {
        // write code here
        int res = 0;
        vector pos(n, 0);
        Recursion(n, 0, pos, res);
        return res;
    }

private:
    static bool IsValid(const vector<int>& pos, const int row, const int col)
    {
        for (int i = 0; i < row; i++) {
            if (row == i || col == pos[i] || abs(row - i) == abs(col - pos[i])) return false;
        }
        return true;
    }

    static void Recursion(const int n, const int row, vector<int>& pos, int& res)
    {
        if (row == n) {
            res++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (IsValid(pos, row, col)) {
                pos[row] = col;
                Recursion(n, row + 1, pos, res);
            }
        }
    }
};
