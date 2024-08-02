/**
 * 这是约瑟夫环问题的一个应用问题。
 */

// 空间复杂度O(1), 时间复杂度O(n)
class BestSolution
{
    int LastRemaining_Solution(const int n, const int m)
    {
        if (n == 1) {
            return 0;
        }

        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i; //这里的last相当于上面递推式中的f(n)，i相当于n
        }

        return last;
    }
};

// 空间复杂度O(n), 时间复杂度O(n)
class MySolution
{
public:
    int LastRemaining_Solution(const int n, const int m)
    {
        if (n == 1) {
            return 0;
        }

        return (m + LastRemaining_Solution(n - 1, m)) % n;
    }
};