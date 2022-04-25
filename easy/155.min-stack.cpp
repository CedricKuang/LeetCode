/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <cmath>
using namespace std;

class MinStack {
public:
    MinStack() {
        min_val = INT_MAX;
        top_pos = 0;
    }
    
    void push(int val) {
        m_stack[top_pos] = val;
        if (val < min_val)
        {
            min_val = val;
        }
        top_pos++;
    }
    
    void pop() {
        top_pos--;
        if (m_stack[top_pos] == min_val && top_pos != 0)
        {
            int new_min = m_stack[0];
            for (int i = 0; i < top_pos; i++)
            {
                if (m_stack[i] < new_min)
                    new_min = m_stack[i];
            }
            min_val = new_min;
        }
        if (top_pos == 0)
            min_val = INT_MAX;
    }
    
    int top() {
        return m_stack[top_pos - 1];
    }
    
    int getMin() {
        return min_val;
    }
private:
    int min_val;
    int top_pos;
    int m_stack[40000];
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

