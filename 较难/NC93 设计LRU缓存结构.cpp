#include "../common-header.hpp"

class Solution
{
public:
    Solution(const int capacity) : capacity_(capacity) {}

    int get(const int key)
    {
        if (key_value_.contains(key)) {
            update_key(key);
            return key_value_[key];
        }
        return -1;
    }

    void set(const int key, const int value)
    {
        if (key_value_.contains(key)) {
            update_key(key);
            key_value_[key] = value;
        } else {
            if (capacity_ <= size_) {
                remove_lru_key();
            }
            insert_key(key, value);
        }
    }

private:
    int capacity_;
    int size_ = 0;
    unordered_map<int, int> key_value_;
    list<int> insert_key_order_;

    void update_key(const int key)
    {
        insert_key_order_.remove(key);
        insert_key_order_.push_back(key);
    }

    void remove_lru_key()
    {
        const auto last_recent_used_key = insert_key_order_.front();
        insert_key_order_.pop_front();
        key_value_.erase(last_recent_used_key);
        size_--;
    }

    void insert_key(int key, int value)
    {
        insert_key_order_.push_back(key);
        key_value_.emplace(key, value);
        size_++;
    }
};