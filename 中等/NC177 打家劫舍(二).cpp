#include "../common-header.hpp"

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        vector dp(nums.size() + 1, 0);

        // Rob the first house.
        dp[1] = nums[0];
        for (size_t i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }
        const int res = dp[nums.size() - 1];

        // Do not rob the first house.
        dp.clear();
        dp[1] = 0;
        for (size_t i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }
        return max(res, dp[nums.size()]);
    }
};
