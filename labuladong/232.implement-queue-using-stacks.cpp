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
        
    }
    
    void push(int x) {
        my_stack.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while (!my_stack.empty())
        {
            temp.push(my_stack.top());
            my_stack.pop();
        }
        int ans = temp.top();
        temp.pop();
        while (!temp.empty())
        {
            my_stack.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    int peek() {
        stack<int> temp;
        while (!my_stack.empty())
        {
            temp.push(my_stack.top());
            my_stack.pop();
        }
        int ans = temp.top();
        while (!temp.empty())
        {
            my_stack.push(temp.top());
            temp.pop();
        }
        return ans;
        
    }
    
    bool empty() {
        return my_stack.empty();
    }
private:
    stack<int> my_stack;
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

