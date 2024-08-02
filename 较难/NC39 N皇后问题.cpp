#include "../common-header.hpp"

class Solution
{
public:
    /**
     * @param n The n.
     * @return The number of queen.
     */
    int Nqueen(const int n)
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
