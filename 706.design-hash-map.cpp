/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
#include <vector>
using namespace std;

class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = is_exits(key);
        if (index == -1)
        {
            map.push_back(pair<int, int>(key, value));
        }
        else
        {
            map[index].second = value;
        }

    }
    
    int get(int key) {
        int index = is_exits(key);
        if (index == -1)
            return -1;
        else    
            return map[index].second;
    }
    
    void remove(int key) {
        int index = is_exits(key);
        if (index == -1)
            return;
        else
            map.erase(map.begin() + index);
    }

    int is_exits(int key) {
        for (int i = 0; i < map.size(); i++)
            if (key == map[i].first)
                return i;
        return -1;
    }
private:
    vector<pair<int, int>> map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

