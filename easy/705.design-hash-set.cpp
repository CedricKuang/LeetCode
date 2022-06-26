/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
#include <vector>
using namespace std;


class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (contains(key))
            return;
        else
            set.push_back(key);
    }
    
    void remove(int key) {
        if (!contains(key))
            return;
        else
        {
            for (int i = 0; i < set.size(); i++)
                if (set[i] == key)
                {
                    set.erase(set.begin() + i);
                    return;
                }
        }
        
    }
    
    bool contains(int key) {
        for (int i = 0; i < set.size(); i++)
            if (set[i] == key)
                return true;
        return false;
    }
private:
    vector<int> set;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

