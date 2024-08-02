#include "../common-header.hpp"

class Solution
{
public:
    void merge(int A[], const int m, int B[], const int n)
    {
        int copy_to_index = m + n - 1;
        int copy_from_a_index = m - 1;
        int copy_from_b_index = n - 1;

        while (copy_to_index >= 0) {
            const int a = copy_from_a_index >= 0 ? A[copy_from_a_index] : -10000;
            const int b = copy_from_b_index >= 0 ? B[copy_from_b_index] : -10000;
            A[copy_to_index--] = a < b ? B[copy_from_b_index--] : A[copy_from_a_index--];
        }
    }
};