#include "../common-header.hpp"

class Solution
{
public:
    vector<int> FindNumsAppearOnce(vector<int>& nums)
    {
        vector<int> res;
        res.reserve(2);
        map<int, uint8_t> nums_count;

        for (const auto& n : nums) {
            nums_count[n]++;
        }

        for (const auto& [k, v] : nums_count) {
            if (v == 1u) {
                res.emplace_back(k);
            }
        }

        return res;
    }
};

class BestSolution
{
public:
    vector<int> FindNumsAppearOnce(vector<int>& nums)
    {
        int tmp = 0;
        for (const int& num : nums) {
            tmp ^= num;
        }

        int mask = 1;
        while ((tmp & mask) == 0) {
            mask <<= 1;
        }

        int a = 0;
        int b = 0;
        for (const int& num : nums) {
            if ((num & mask) == 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        if (a > b) {
            const int c = a;
            a = b;
            b = c;
        }
        return {a, b};
    }
};