/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        num = 0;
    }
    
    void push(int x) {
        m_queue.push(x);
        num++;
    }
    
    int pop() {
        int result = 0;
        stack<int> temp;
        for (int i = 0; i < num; i++)
        {
            if (i == (num - 1))
            {
                result = m_queue.top();
                m_queue.pop();
            }
            else
            {
                temp.push(m_queue.top());
                m_queue.pop();
            }
        }
        num--;
        for (int i = 0; i < num; i++)
        {
            m_queue.push(temp.top());
            temp.pop();
        }
        return result;
    }
    
    int peek() {
        int result = 0;
        stack<int> temp;
        for (int i = 0; i < num; i++)
        {
            if (i == (num - 1))
            {
                result = m_queue.top();
            }
            temp.push(m_queue.top());
            m_queue.pop();
        }
        for (int i = 0; i < num; i++)
        {
            m_queue.push(temp.top());
            temp.pop();
        }
        return result;
    }
    
    bool empty() {
        return m_queue.empty();
    }
private:
    int num;
    stack<int> m_queue;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

