/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(letters[mid] <= target){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return letters[low] > target ? letters[low] : letters[0];
    }
};
// @lc code=end

