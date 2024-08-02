#include "../common-header.hpp"

class Solution
{
public:
    string LCS(const string& s1, const string& s2)
    {
        auto len1 = s1.length();
        auto len2 = s2.length();
        vector dp(len1 + 1, vector(len2 + 1, 0));

        for (size_t i = 1; i <= len1; i++) {
            for (size_t j = 1; j <= len2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        if (dp[len1][len2] == 0) {
            return to_string(-1);
        }

        string res;
        while (len1 > 0 && len2 > 0) {
            if (s1[len1 - 1] == s2[len2 - 1]) {
                res.push_back(s1[len1 - 1]);
                len1--;
                len2--;
            } else {
                if (dp[len1][len2 - 1] >= dp[len1 - 1][len2]) {
                    len2--;
                } else {
                    len1--;
                }
            }
        }

        ranges::reverse(res);
        return res;
    }
};