#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices)
    {
        int min_price = 1234567890;
        int max_profit = 0;
        for (const int x : prices) {
            min_price = min(min_price, x);
            max_profit = max(max_profit, x - min_price);
        }
        return max_profit;
    }
};