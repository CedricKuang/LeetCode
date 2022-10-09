/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <queue>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.size() >= min_heap.size())
        {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else
        {
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (min_heap.size() > max_heap.size())
            return min_heap.top();
        else if (min_heap.size() < max_heap.size())
            return max_heap.top();
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

