#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param input int整型vector 
     * @param k int整型 
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k)
    {
        vector<int> least_numbers;
        least_numbers.reserve(k);

        make_heap(input.begin(), input.end(), greater<>());
        for (int i = 0; i < k; i++) {
            pop_heap(input.begin(), input.end(), greater<>());
            least_numbers.emplace_back(input.back());
            input.pop_back();
        }

        return least_numbers;
    }
};