#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * lfu design
     * @param operators int整型vector<vector<>> ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LFU(vector<vector<int>>& operators, int k)
    {
        vector<int> res;
        k_ = static_cast<size_t>(k);
        for (const auto& op : operators) {
            if (op[0] == 1) {
                // Set
                Set(op[1], op[2]);
            } else {
                int value;
                res.emplace_back(Get(op[1], &value) ? value : -1);
            }
        }
        return res;
    }

private:
    bool Get(const int key, int* value)
    {
        if (key_value_store_.contains(key)) {
            *value = key_value_store_[key];
            UpdateKeyMeta(key);
            return true;
        }
        return false;
    }

    void Set(const int key, const int value)
    {
        if (key_value_store_.contains(key)) {
            key_value_store_[key] = value;
            UpdateKeyMeta(key);
        } else {
            if (key_value_store_.size() == k_) {
                const int deleted_key = GetLfuKey();
                key_value_store_.erase(deleted_key);
                key_used_count_.erase(deleted_key);
                key_order_.remove(deleted_key);
            }

            key_used_count_[key] = 1;
            key_value_store_[key] = value;
            key_order_.push_back(key);
        }
    }

    void UpdateKeyMeta(const int key)
    {
        key_used_count_[key]++;
        key_order_.remove(key);
        key_order_.push_back(key);
    }

    int GetLfuKey()
    {
        auto min_value = numeric_limits<int>::max();
        for (const auto& value : key_used_count_ | views::values) {
            if (value < min_value) {
                min_value = value;
            }
        }

        unordered_set<int> min_keys;
        for (const auto& [key, value] : key_used_count_) {
            if (value == min_value) {
                min_keys.insert(key);
            }
        }

        // Get key.
        if (min_keys.size() > 1) {
            for (int k : key_order_) {
                if (min_keys.contains(k)) {
                    return k;
                }
            }
        }
        return *min_keys.begin();
    }

    unordered_map<int, int> key_value_store_;
    unordered_map<int, int> key_used_count_;
    list<int> key_order_; // Head out, tail in.
    size_t k_ = 1;
};