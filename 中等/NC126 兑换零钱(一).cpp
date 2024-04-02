#include "../common-header.hpp"

class Solution
{
public:
    int minMoney(vector<int>& arr, int aim)
    {
        vector dp(aim + 1, aim + 1);
        dp[0] = 0;

        for (int i = 1; i <= aim; i++) {
            for (const int money : arr) {
                if (i > money) {
                    dp[i] = min(dp[i], dp[i - money] + 1);
                }
            }
        }

        return dp[aim] > aim ? -1 : dp[aim];
    }
};