#include <vector>
using namespace std;

/**
 * 快速排序算法
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr)
    {
        MySort(arr, 0, arr.size() - 1);
        return arr;
    }

private:
    void MySort(vector<int>& arr, int left, int right)
    {
        if (left < right) {
            int pivot = arr[left];
            int low = left + 1;
            int high = right;

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