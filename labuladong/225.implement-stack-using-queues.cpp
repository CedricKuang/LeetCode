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
        
    }
    
    void push(int x) {
        my_queue.push(x);
    }
    
    int pop() {
        for (int i = 0; i < my_queue.size() - 1; i++)
        {
            my_queue.push(my_queue.front());
            my_queue.pop();
        }
        int ans = my_queue.front();
        my_queue.pop();
        return ans;
    }
    
    int top() {
        for (int i = 0; i < my_queue.size() - 1; i++)
        {
            my_queue.push(my_queue.front());
            my_queue.pop();
        }
        int ans = my_queue.front();
        my_queue.push(ans);
        my_queue.pop();
        return ans;
    }
    
    bool empty() {
        return my_queue.empty();
    }
private:
    queue<int> my_queue;
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

