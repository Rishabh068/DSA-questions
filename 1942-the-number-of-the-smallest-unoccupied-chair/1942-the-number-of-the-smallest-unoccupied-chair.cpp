class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > busy; 
        priority_queue<int, vector<int>, greater<int>> free; 
        for(int i=0;i<n;++i){
            times[i].push_back(i);
        }		
        sort(times.begin(),times.end());
        
		int new_chair = 0; 
        for(int i=0;i<n;++i){
            int arrival = times[i][0]; 
            int leave_time = times[i][1];
            int fr = times[i][2]; 
           
            while(!busy.empty() && busy.top().first <= arrival){
                free.push(busy.top().second);
                busy.pop();
            }   
          
            if(free.empty()){
                if(fr  == targetFriend) return new_chair;
                busy.push({leave_time,new_chair});
                new_chair++;
            }
            else{
                int x = free.top();
                free.pop();
                if( fr  == targetFriend) return x; 
                busy.push({leave_time,x});
            }
        }
        return -1;
    }
    
};