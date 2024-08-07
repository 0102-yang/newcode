#include "../common-header.hpp"

class Solution
{
public:
    void push(int value)
    {
        m_stack.push(value);
        if (m_min_stack.empty() || m_min_stack.top() > value) {
            m_min_stack.push(value);
        } else {
            m_min_stack.push(m_min_stack.top());
        }
    }

    void pop()
    {
        m_stack.pop();
        m_min_stack.pop();
    }

    int top() { return m_stack.top(); }

    int min() { return m_min_stack.top(); }

private:
    stack<int> m_stack;
    stack<int> m_min_stack;
};
