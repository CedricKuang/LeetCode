/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
   class Compare{
	public:
        bool operator() (vector<int>& v1, vector<int>& v2){   
            if(v1[1]==v2[1]) return (v1[2]>v2[2]);
            return (v1[1]>v2[1]);
        }
    };
    
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        //adding indices to the tasks and sorting on the basis of enqueue time
        for(int i=0; i<tasks.size(); i++) tasks[i].push_back(i); 
        sort(tasks.begin(), tasks.end());

        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<int> ans;
        
        int i= 0;
        long long int time= 0;
        while(i<tasks.size() || !pq.empty()){
            
				long long int idleTime= 0; //this will store the time for which CPU does not do anything
				
                //CPU is idle, adds all the tasks with same enqueue time to its pq
                if(pq.empty()){
					idleTime= ((long long int)tasks[i][0])-time;
                    int enqTime= tasks[i][0];
                    for(; i<tasks.size(); i++){
                        if(tasks[i][0]!=enqTime) break;
                        pq.push(tasks[i]);
                    }
                }
                
                //CPU starts processing the top process (add processing time of top to time)
                if(!pq.empty()){
					if(idleTime>0) time+= pq.top()[1]+idleTime;  //we need to add in the time elapsed when the CPU was idle 
                    else time += pq.top()[1];
                    
                    ans.push_back(pq.top()[2]);
                    pq.pop();
                
                    //in this duration the enqueue time of these processes is also reached, adding to pq
                    while(i<tasks.size() && ((long long int)tasks[i][0])<=time){
                        pq.push(tasks[i]);
                        i++;
                    }
                    
                }
        }
		
        return ans;
};
};
// @lc code=end

