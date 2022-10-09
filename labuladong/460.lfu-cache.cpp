/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int _cap;     // cache capacity
    int _minFreq; // min frequency
    unordered_map<int, list<int>> _f2klist;         // frequency -> key list
    unordered_map<int, list<int>::iterator> _k2pos; // key       -> iterator in key list
    unordered_map<int, pair<int, int>> _k2vf;       // key       -> (val, frequency)
    
public:
    LFUCache(int capacity):_cap(capacity), _minFreq(0) { }
    
    int get(int key) 
    {
        if (!_k2pos.count(key)) return -1;
        
        // increment existing key's frequency by 1
        int freq = _k2vf[key].second++;
        _f2klist[freq].erase(_k2pos[key]);
        _f2klist[freq+1].push_back(key);
        _k2pos[key] = --_f2klist[freq+1].end();
        
        // update min freq
        if (_f2klist[_minFreq].empty()) _f2klist.erase(_minFreq++);
        
        return _k2vf[key].first;
    }
    
    void put(int key, int value) 
    {
        if (_cap <= 0) return;
        
        // update existing key's value
        if (get(key) != -1) {
            _k2vf[key].first = value;
            return;
        }
 
        // evict oldest min freq key if reach capacity
        if (_k2vf.size() == _cap) { 
            int k = _f2klist[_minFreq].front(); // key to evict
            _k2pos.erase(k);
            _k2vf.erase(k);
            _f2klist[_minFreq].pop_front();
            if (_f2klist[_minFreq].empty()) _f2klist.erase(_minFreq);
        }
        
        // insert new key with freq=1
        _k2vf[key] = {value, 1};
        _f2klist[_minFreq = 1].push_back(key);
        _k2pos[key] = --_f2klist[1].end();        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

