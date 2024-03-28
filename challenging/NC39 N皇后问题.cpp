#include "../common-header.hpp"

class Solution
{
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param n int���� the n
     * @return int����
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
