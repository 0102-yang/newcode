#include "../common-header.hpp"

/**
 * 快速排序算法
 */
class Solution
{
public:
    vector<int> MySort(vector<int>& arr)
    {
        MySort(arr, 0, arr.size() - 1);
        return arr;
    }

private:
    void MySort(vector<int>& arr, const unsigned left, const unsigned right)
    {
        if (left < right) {
            const int pivot = arr[left];
            unsigned low = left + 1;
            unsigned high = right;

            while (true) {
                while (low <= high && arr[high] >= pivot) {
                    high--;
                }
                while (low <= high && arr[low] <= pivot) {
                    low++;
                }

                if (low <= high) {
                    swap(arr[low], arr[high]);
                } else {
                    break;
                }
            }

            swap(arr[left], arr[high]);
            MySort(arr, left, high - 1);
            MySort(arr, high + 1, right);
        }
    }
};