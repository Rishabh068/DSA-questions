class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    
        queue<int>q;
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }
        int time=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            tickets[x]--;
            time++;
            if(x==k&&tickets[x]==0)
                return time;
            if(tickets[x]!=0)
                q.push(x);
            
        }
        return time;
        
    }
};