#include "../common-header.hpp"

class Solution
{
public:
    int minNumberDisappeared(vector<int>& nums)
    {
        unordered_set<int> nums_exist;

        for (const auto& num : nums) {
            if (num <= 0) {
                continue;
            }
            nums_exist.insert(num);
        }

        for (int i = 1;; i++) {
            if (!nums_exist.contains(i)) {
                return i;
            }
        }
    }
};

class BestSolution
{
public:
    int minNumberDisappeared(vector<int>& nums)
    {
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) <= n) {
                nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};