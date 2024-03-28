#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return int整型
     */
    int FirstNotRepeatingChar(string str)
    {
        std::unordered_map<char, int> character_count;

        for (char c : str) {
            character_count[c]++;
        }

        for (unsigned i = 0; i < str.length(); i++) {
            if (character_count[str[i]] == 1) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};