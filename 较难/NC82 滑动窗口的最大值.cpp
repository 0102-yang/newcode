#include "../common-header.hpp"

class Solution
{
public:
    vector<int> maxInWindows(const vector<int>& num, const int size)
    {
        vector<int> max_values;
        if (size == 0 || static_cast<size_t>(size) > num.size()) {
            return max_values;
        }

        vector<int> heap;
        heap.reserve(size);
        for (size_t i = 0; i < size; i++) {
            heap.push_back(num[i]);
        }
        ranges::make_heap(heap);
        max_values.push_back(heap.front());

        size_t begin_idx = 0;
        size_t end_idx = begin_idx + size;
        while (end_idx < num.size()) {
            const auto itr = ranges::find(heap, num[begin_idx]);
            heap.erase(itr);
            heap.push_back(num[end_idx]);
            ranges::make_heap(heap);
            max_values.push_back(heap.front());

            begin_idx++;
            end_idx++;
        }

        return max_values;
    }
};