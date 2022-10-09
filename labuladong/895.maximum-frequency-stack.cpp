/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        vf[val]++;
        int freq = vf[val];
        fv[freq].push(val);
        max_freq = max(max_freq, freq);
    }
    
    int pop() {
        int v = fv[max_freq].top();
        fv[max_freq].pop();

        vf[v]--;
        if (fv[max_freq].empty())
            max_freq--;
        return v;
    }
private:
    int max_freq;
    unordered_map<int, int> vf;
    unordered_map<int, stack<int>> fv;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

