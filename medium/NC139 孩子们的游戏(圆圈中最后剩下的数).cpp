/**
 * 这是约瑟夫环问题的一个应用问题。
 */

// 空间复杂度O(1), 时间复杂度O(n)
class BestSolution
{
    int LastRemaining_Solution(int n, int m)
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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 1) {
            return 0;
        }

        return (m + LastRemaining_Solution(n - 1, m)) % n;
    }
};