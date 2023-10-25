#include "../common-header.hpp"

class BestSolution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberInRotateArray(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }

        return nums[left];
    }
};

class MySolution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberInRotateArray(vector<int>& nums) { return minNumberInRotateArray(nums, 0, nums.size() - 1); }

private:
    int minNumberInRotateArray(const vector<int>& nums, int left, int right)
    {
        if (abs(left - right) <= 1) {
            return min(nums[left], nums[right]);
        }
        int mid = (left + right) / 2;
        return min(minNumberInRotateArray(nums, left, mid), minNumberInRotateArray(nums, mid, right));
    }
};