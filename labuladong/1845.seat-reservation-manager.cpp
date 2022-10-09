/*
 * @lc app=leetcode id=1845 lang=cpp
 *
 * [1845] Seat Reservation Manager
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            pq.push(i);
    }
    
    int reserve() {
        int a = pq.top();
        pq.pop();
        return a;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end

