class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int time=0;
       for(int i=0;i<customers.size();i++)
       {
           if(grumpy[i]==0)
               time+=customers[i];
       }
        int j=0,i=0;
       int  maxtime=INT_MIN;
        while(j<customers.size()){
           if(grumpy[j]==1)
               time+=customers[j];
            while(j-i+1>minutes){
                if(grumpy[i]==1)
                    time-=customers[i];
                i++;
            }
             maxtime=max(maxtime,time);
            j++;
        }
        return maxtime;
    }
};