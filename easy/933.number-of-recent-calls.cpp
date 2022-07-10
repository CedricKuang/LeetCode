/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
#include <deque>
using namespace std;

class RecentCounter {
public:
    deque<int> dq;
    RecentCounter() {

    }
    
    int ping(int t) {
        dq.push_back(t);
        while(!dq.empty() && dq.front()<t-3000)
            dq.pop_front();
        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
