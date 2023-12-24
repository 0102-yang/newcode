#include <algorithm>

#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        class Adder
        {
        public:
            char operator()(const char a, const char b)
            {
                char added_char = a + b - '0' + (carry_flag ? 1 : 0);
                if (added_char > '9') {
                    added_char -= 10;
                    carry_flag = true;
                } else {
                    carry_flag = false;
                }

                return added_char;
            }

            bool carry_flag = false;
        };

        Adder adder;
        const int s_length = static_cast<int>(s.length());
        const int t_length = static_cast<int>(t.length());
        const int min_length = min(s_length, t_length);
        const int max_length = max(s_length, t_length);
        const string& longer_str = s_length > t_length ? s : t;

        string result;
        result.reserve(max(s_length, t_length));

        for (int i = 0; i < min_length; i++) {
            const char sc = s[s_length - 1 - i];
            const char tc = t[t_length - 1 - i];

            result.push_back(adder(sc, tc));
        }

        for (int i = 0; i < max_length - min_length; i++) {
            const char mc = longer_str[max_length - min_length - 1 - i];

            result.push_back(adder(mc, '0'));
        }

        if (adder.carry_flag) {
            result.push_back('1');
        }

        ranges::reverse(result);
        return result;
    }
};