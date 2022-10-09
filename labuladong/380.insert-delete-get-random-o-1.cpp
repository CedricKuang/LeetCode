/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valtoindex.count(val))
            return false;
        
        valtoindex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!valtoindex.count(val))
            return false;
        int index = valtoindex[val];
        valtoindex[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        valtoindex.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    unordered_map<int, int> valtoindex;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

