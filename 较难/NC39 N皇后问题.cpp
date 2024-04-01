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
        int result = 0;
        vector board(n, 0);
        Nqueen(n, 0, board, result);
        return result;
    }

private:
    static bool IsValid(const vector<int>& board, const int row, const int col)
    {
        for (int i = 0; i < row; i++) {
            if (row == i || col == board[i] || abs(row - i) == abs(col - board[i])) return false;
        }
        return true;
    }

    static void Nqueen(const int n, const int row, vector<int>& board, int& result)
    {
        if (row == n) {
            result++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (IsValid(board, row, col)) {
                board[row] = col;
                Nqueen(n, row + 1, board, result);
            }
        }
    }
};
