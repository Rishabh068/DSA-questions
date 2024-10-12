class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        if(v1[0]<v2[0])
            return true;
        else if(v1[0]==v2[0]&&v1[1]<v2[1])
            return true;
        return false;
    }
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=0;i<intervals.size();i++){
            if(!pq.empty()&&pq.top()<intervals[i][0]){
                pq.pop();   
            } 
            pq.push(intervals[i][1]);  
        }
        return pq.size();   
    }
};