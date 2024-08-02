#include "../common-header.hpp"

class Solution
{
public:
    int rob(const vector<int>& nums)
    {
        vector dp(nums.size(), 0);
        dp[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            if (i == 1) {
                dp[i] = max(nums[i], dp[0]);
            } else {
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
        }

        return dp[nums.size() - 1];
    }
};