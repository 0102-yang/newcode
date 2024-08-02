#include "../common-header.hpp"

class Solution
{
public:
    int editDistance(const string& str1, const string& str2)
    {
        const auto length1 = str1.length();
        const auto length2 = str2.length();

        vector dp(length1 + 1, vector<int>(length2 + 1));
        dp[0][0] = 0;
        for (size_t i = 1; i <= length1; i++) {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        for (size_t j = 1; j <= length2; j++) {
            dp[0][j] = dp[0][j - 1] + 1;
        }

        for (size_t i = 1; i <= length1; i++) {
            for (size_t j = 1; j <= length2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[length1][length2];
    }
};