/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {
        num = 0;
    }
    
    void push(int x) {
        m_stack.push(x);
        num++;
    }
    
    int pop() {
        int result = 0;
        for (int i = 0; i < num; i++)
        {
            if (i == (num - 1))
                result = m_stack.front();
            else
                m_stack.push(m_stack.front());
            m_stack.pop();
        }
        num--;
        return result;
    }
    
    int top() {
        int result = 0;
        for (int i = 0; i < num; i++)
        {
            if (i == (num - 1))
                result = m_stack.front();
            m_stack.push(m_stack.front());
            m_stack.pop();
        }
        return result;
    }
    
    bool empty() {
        return m_stack.empty();
    }
private:
    queue<int> m_stack;
    int num;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

