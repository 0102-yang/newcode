#include "../common-header.hpp"

class Solution
{
public:
    int sqrt(const int x)
    {
        if (x == 1) {
            return 1;
        }

        int left = 1;
        int right = x;
        while (left <= right) {
            const int mid = (left + right) / 2;

            if (x / mid >= mid && x / (mid + 1) < mid + 1) {
                return mid;
            }

            if (x / mid > mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};

class BestSolution
{
public:
    int sqrt(const int x)
    {
        if (x <= 0) {
            return 0;
        }

        int ans = 1;
        int num = 1;
        int i = 3;
        while (num + i <= x) {
            num += i;
            ans++;
            i += 2;
        }
        return ans;
    }
};
