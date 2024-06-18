class Solution {
public:
   static bool comp(pair<int,int>p1,pair<int,int>p2){
        return p1.first>p2.first;
                                               }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>jobs;
        for(int i=0;i<profit.size();i++){
            jobs.push_back({profit[i],difficulty[i]});
        }
        sort(jobs.begin(),jobs.end(),comp);
        sort(worker.begin(),worker.end());
       long long int maxprofit=0;
        for(int i=0;i<worker.size();i++){
            int j=0;
            while(jobs[j].second>worker[i]){
                j++;
            }
            if(j!=jobs.size())
            maxprofit+=jobs[j].first;
        }
        return maxprofit;
        
    }
};