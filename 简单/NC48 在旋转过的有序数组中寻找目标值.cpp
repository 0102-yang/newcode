#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(const vector<int>& nums, const int target)
    {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);

        while (left <= right) {
            const int mid = (left + right) / 2;
            const int left_num = nums[left];
            const int right_num = nums[right];
            const int mid_num = nums[mid];

            if (mid_num == target) {
                return mid;
            }
            if (right_num == target) {
                return right;
            }
            if (left_num == target) {
                return left;
            }

            if (left_num > mid_num) {
                if (target > mid_num && target < right_num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (target > left_num && target < mid_num) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};