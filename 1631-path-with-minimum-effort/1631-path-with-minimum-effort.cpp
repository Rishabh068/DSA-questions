class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e8));
        pq.push({0,{0,0}});
        int mineffort=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==n-1&&y==m-1)
                return diff;
            pq.pop();
            vector<pair<int,int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
            for(auto it:dirs){
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0&&y1>=0&&x1<n&&y1<m){
                    int neweffort=max(abs(heights[x1][y1]-heights[x][y]),diff);
                    if(neweffort<dis[x1][y1]){
                        dis[x1][y1]=neweffort;
                        pq.push({neweffort,{x1,y1}});
                    }
                    
                }
            }
        }
        return 0;
        
    }
};