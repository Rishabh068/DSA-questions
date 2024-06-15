class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>>pq;
        vector<pair<int,int>>vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        
        while(k!=0){
            while(vec[i].first<=w&&i<vec.size()){
                pq.push({vec[i].second,vec[i].first});
                i++;
            }
            if(pq.empty())
                break;
            cout<<pq.top().first<<endl;
            auto project=pq.top();
            pq.pop();
            w+=project.first;
            k--;
            
            
        }
        return w;
        
        
    }
    
};
    